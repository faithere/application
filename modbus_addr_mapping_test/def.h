#ifndef _DEF_H_
#define _DEF_H_

#include "mytypes.h"

#define MAX_NUMBER 10

typedef struct LEVEL1
{
  uint8_t version;
  uint8_t vendor;
  
  uint16_t magic;
  uint16_t salary;

  uint8_t male;
  uint16_t school;

  uint8_t score;
}level1;

typedef struct LEVEL2
{
  uint8_t id1;
  uint8_t id2;
  
  uint16_t id3;
  uint8_t id4;

  uint8_t id5;

  uint16_t id6;
  
}level2;

typedef struct LEVEL3
{
  uint8_t tid1;
  uint8_t tid2;
  
  uint16_t tid3;
  uint8_t tid4;

  uint32_t tid5;

  uint16_t tid6;
  
}level3;


struct GLOBALDATA
{
  level1 gd1;
  level2 gd2[MAX_NUMBER];
  level3 gd3;
}globaldata;

#endif
