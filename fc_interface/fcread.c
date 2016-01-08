#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
  int fileno,result,offset;
  int buf_read=0x0;

  if (argc != 2)
    {
      printf("Error!  ");
      printf("Usage:fcread offset\n");
      return -1;
    }
  
  fileno=open("/dev/fc1553_card",O_RDWR);
  if (fileno==-1)
    {
      printf("open /dev/fc1553 failed!\n");
      return -1;
    }
  //printf("Open Success!\n");
  
  //printf("Please input the number to write:\n");
  //scanf("%x\n",&buf_write);

  offset=strtol(argv[1],NULL,0);
  
  lseek(fileno,offset,SEEK_SET);
  read(fileno,&buf_read,sizeof(buf_read));
  
  printf("read value=0x%x\n",buf_read);
  
  close(fileno);
  return 0;
}
