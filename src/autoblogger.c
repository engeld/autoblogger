#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( int argc, char *argv[] )
{
  char        item[] 	= "", status;
  FILE        *fp;

  if( argc != 3 ){
    fprintf( stderr, "Usage: %s <link.txt>\n", argv[0]);
    exit( EXIT_FAILURE );
  }
  
  return EXIT_SUCCESS;
}
