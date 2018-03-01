#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <strings.h>
#define BUF_LENGTH 256

int main(int argc, char* argv[])
{
  if(argc < 3){
    printf("Error on function call\n");
    exit(1);
  }
  FILE *src, *dst;
  char buf[BUF_LENGTH];

  if ( ( src = fopen(argv[1], "r" ) ) == NULL )
  {
    printf("Error : %d\n",errno);
    exit(2);
  }

  if ( ( dst = fopen(argv[2], "w" ) ) == NULL )
  {
    printf("Error : %d\n",errno);
    exit(3);
  }
  while( ( fgets( buf, BUF_LENGTH, src ) ) != NULL )
  {
    fputs( buf, dst );
  }
  fclose( src );
  fclose( dst );
  exit(0);  // zero é geralmente indicativo de "sucesso"
}
