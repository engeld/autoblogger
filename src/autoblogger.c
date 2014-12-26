#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( int argc, char *argv[] )
{
  FILE        *in;
  char        buf[BUFSIZ];

  if( argc != 2 ){
    fprintf( stderr, "Usage: %s <link.txt>\n", argv[0]);
    exit( EXIT_FAILURE );
  }

  in = fopen( argv[1], "r");
  if( in == NULL ){
    perror( "Unable to open the file" );
    exit( EXIT_FAILURE );
  }
  
  fread( buf, 1, sizeof( buf ), in);
  printf( "%s\n", buf );

  fclose( in );
  
  return EXIT_SUCCESS;
}
