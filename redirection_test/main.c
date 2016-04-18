#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char *filename;
  
  if (argc !=2)
    {
      fprintf(stderr, "Usage:useupper filename\n");
      exit(1);
    }
  
  filename=argv[1];

  if(!freopen(filename,"r",stdin))
    {
      fprintf(stderr,"could not redirect stdin from file %s\n",filename);
      exit(2);
    }
  execl("./upper",NULL,0);

  perror("could not exec ./upper");
  exit(3);

}
