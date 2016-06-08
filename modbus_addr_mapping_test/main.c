#include "mytypes.h"
#include "def.h"
#include <stdio.h>

uint8_t rxbuff[4]={0};
extern struct GLOBALDATA globaldata;

void globaldata_init()
{
  int i;
  //one
  //globaldata.flag=0x0;
  //two
  globaldata.gd1.version=0x01;
  globaldata.gd1.vendor=0x02;
  globaldata.gd1.magic=0x0304;
  globaldata.gd1.salary=0x0506;

  globaldata.gd1.male=0x07;
  globaldata.gd1.school=0x0809;

  globaldata.gd1.score=0x0a;
  //three
  for(i=0;i<MAX_NUMBER;i++)
    {
      globaldata.gd2[i].id1=0x0;
      globaldata.gd2[i].id2=0x01;
      globaldata.gd2[i].id3=0x0304;
      globaldata.gd2[i].id4=0x05;
      globaldata.gd2[i].id5=0x06;
      globaldata.gd2[i].id6=0x0708;
    }
  //four
  globaldata.gd3.tid1=0x0;
  globaldata.gd3.tid2=0x01;
  globaldata.gd3.tid3=0x0304;
  globaldata.gd3.tid4=0x05;
  globaldata.gd3.tid5=0x06070809;
  globaldata.gd3.tid6=0x0a;

}

int main(void)
{
  globaldata_init();
  //  printf("0x%x\n",globaldata.gd2[9].id2);
  return 0;
}

