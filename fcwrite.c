#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
typedef struct buf_write
  {
    int offset;
    int value;
  }BUF_WRITE;
*/

int main(int argc, char **argv)
{
  int fileno,result,offset,value;
  //BUF_WRITE *buf_write;
  
  if (argc != 3)
    {
      printf("Error!  ");
      printf("Usage:fcwrtie offset value\n");
      return -1;
    }

  
  fileno=open("/dev/fc1553_card",O_RDWR);
  if (fileno==-1)
    {
      printf("open /dev/fc1553 failed!\n");
      return -1;
    }
  
  //printf("Open Success!\n");
  
  offset=strtol(argv[1],NULL,0);
  value=strtol(argv[2],NULL,0);
  
  /*
  buf_write->offset=offset;
  buf_write->value=value;
  */
	
  /*
  buf_write=0x5678;
  printf("Please input the number to write:\n");
  scanf("%x\n",&buf_write);
  */
  
  lseek(fileno,offset,SEEK_SET);	
  result=write(fileno,&value,sizeof(value));
  
  if (result==sizeof(value));
    //printf("write OK!\n");
  else
    {
      printf("write error!\n");
      close(fileno);
      return -1;
    }
  close(fileno);
  return 0;
}
