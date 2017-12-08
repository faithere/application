#!/bin/bash

PACKAGES=" "
EXCLUDE_FROM_WORLD="1"

COMPRESSISO="0"

BOOTIMG_VOLUME_ID="boot"
BOOTIMG_EXTRA_SPACE="512"

#build_directory=/home/wrsadmin/build/toshiba/server-xorg

#set -x
echo "lets begining ..."

build_fat_img() {
	if [ $# -neq 2 ] ; then
        echo "the para need 2"
    fi
    
    FATSOURCEDIR=$1
	FATIMG=$2

	# Calculate the size required for the final image including the
	# data and filesystem overhead.
	# Sectors: 512 bytes
	#  Blocks: 1024 bytes

	# Determine the sector count just for the data
	SECTORS=$(expr $(du --apparent-size -ks ${FATSOURCEDIR} | cut -f 1) \* 2)

	# Account for the filesystem overhead. This includes directory
	# entries in the clusters as well as the FAT itself.
	# Assumptions:
	#   FAT32 (12 or 16 may be selected by mkdosfs, but the extra
	#   padding will be minimal on those smaller images and not
	#   worth the logic here to caclulate the smaller FAT sizes)
	#   < 16 entries per directory
	#   8.3 filenames only

	# 32 bytes per dir entry
	DIR_BYTES=$(expr $(find ${FATSOURCEDIR} | tail -n +2 | wc -l) \* 32)
	# 32 bytes for every end-of-directory dir entry
	DIR_BYTES=$(expr $DIR_BYTES + $(expr $(find ${FATSOURCEDIR} -type d | tail -n +2 | wc -l) \* 32))
	# 4 bytes per FAT entry per sector of data
	FAT_BYTES=$(expr $SECTORS \* 4)
	# 4 bytes per FAT entry per end-of-cluster list
	FAT_BYTES=$(expr $FAT_BYTES + $(expr $(find ${FATSOURCEDIR} -type d | tail -n +2 | wc -l) \* 4))

	# Use a ceiling function to determine FS overhead in sectors
	DIR_SECTORS=$(expr $(expr $DIR_BYTES + 511) / 512)
	# There are two FATs on the image
	FAT_SECTORS=$(expr $(expr $(expr $FAT_BYTES + 511) / 512) \* 2)
	SECTORS=$(expr $SECTORS + $(expr $DIR_SECTORS + $FAT_SECTORS))

	# Determine the final size in blocks accounting for some padding
	BLOCKS=$(expr $(expr $SECTORS / 2) + ${BOOTIMG_EXTRA_SPACE})

	# Ensure total sectors is an integral number of sectors per
	# track or mcopy will complain. Sectors are 512 bytes, and we
	# generate images with 32 sectors per track. This calculation is
	# done in blocks, thus the mod by 16 instead of 32.
	BLOCKS=$(expr $BLOCKS + $(expr 16 - $(expr $BLOCKS % 16)))

	# mkdosfs will sometimes use FAT16 when it is not appropriate,
	# resulting in a boot failure from SYSLINUX. Use FAT32 for
	# images larger than 512MB, otherwise let mkdosfs decide.
	if [ $(expr $BLOCKS / 1024) -gt 512 ]; then
		FATSIZE="-F 32"
	fi

	# mkdosfs will fail if ${FATIMG} exists. Since we are creating an
	# new image, it is safe to delete any previous image.
	if [ -e ${FATIMG} ]; then
		rm ${FATIMG}
	fi

	if [ -z "${HDDIMG_ID}" ]; then
		mkdosfs ${FATSIZE} -n ${BOOTIMG_VOLUME_ID} -S 512 -C ${FATIMG} \
			${BLOCKS}
	else
		mkdosfs ${FATSIZE} -n ${BOOTIMG_VOLUME_ID} -S 512 -C ${FATIMG} \
		${BLOCKS} -i ${HDDIMG_ID}
	fi

	# Copy FATSOURCEDIR recursively into the image file directly
	mcopy -i ${FATIMG} -s ${FATSOURCEDIR}/* ::/
}

build_iso() {

	#build_fat_img ${EFIIMGDIR} ${ISODIR}/efi.img
      
    mkisofs_compress_opts="-r"
    isohybrid_args="-u"

    cd new-iso	
    
	tree
	
    $MKISOFS -A boot -V boot -o ../boot-uefi.iso -b  isolinux/isolinux.bin -c isolinux/boot.cat \
    -r -no-emul-boot -boot-load-size 4 -boot-info-table \
    -eltorito-alt-boot -eltorito-platform efi -b efi.img -no-emul-boot  .

    cd ..

	isohybrid $isohybrid_args boot-uefi.iso
}

if [ ! -e efi-syslinux ]  
then 
	echo "efi-syslinux missing"
fi


echo -n "Enter your build directory: "
read build_directory

MKISOFS="${build_directory}/bitbake_build/tmp/sysroots/x86_64-linux/usr/bin/mkisofs"
echo "MKISOFS=$MKISOFS"

if [ ! -e $MKISOFS ]  
then 
	echo "build_directory needed"
	exit
fi


echo -n "Enter your sudo passwd: "
read -s sudo_passwd

mkdir -p mnt-64
mkdir -p efi-64
mkdir -p efi

echo

echo $sudo_passwd | sudo -Sk mount $build_directory/export/intel-x86-64-*-dist.iso mnt-64
echo $sudo_passwd | sudo -Sk mount mnt-64/efi.img efi-64

cp efi-64/* efi -rv
rm efi/EFI/BOOT/* -rf
chmod u+w efi-64 -R
cp efi-syslinux/* efi -rv

build_fat_img efi efi.img

mkdir -p new-iso

cp mnt-64/* new-iso -rv
chmod u+w new-iso -R
rm new-iso/EFI/BOOT/* -rf
cp efi-syslinux/EFI/BOOT/* new-iso/EFI/BOOT/ -rv
cp efi.img new-iso -v

build_iso 

echo $sudo_passwd | sudo -Sk umount efi-64
echo $sudo_passwd | sudo -Sk umount mnt-64

rm -rf efi efi-64
rm -rf mnt-64 new-iso
rm efi.img 

echo done!

#set +x

