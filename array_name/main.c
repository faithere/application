#include <stdio.h>

void try_func(char array[])
{
  int large;
  
  large=sizeof(array);
  
  printf("large=%d\n",large);
  printf("array+1=%d\n",*(array+1));
}


int main(void)
{
  int size_name;
  int size_element;
  char array[8]={1,2,3,4,5,6,7,8};
  
  size_name=sizeof(array);
  size_element=sizeof(array[0]);
  
  printf("size_name=%d,size_element=%d\n",size_name,size_element);

  //function call
  try_func(array[]);
  return 0;
  
}
