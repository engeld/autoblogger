#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "html.h"

int main( int argc, char *argv[] )
{
  FILE        *in;
  char        buf[BUFSIZ];

  /* Handle arguments */
  if( argc != 2 ){
    fprintf( stderr, "Usage: %s <link.txt>\n", argv[0]);
    exit( EXIT_FAILURE );
  }

  /* Handle file-opening */
  in = fopen( argv[1], "r");
  if( in == NULL ){
    perror( "Unable to open the file" );
    exit( EXIT_FAILURE );
  }
  
  /* depending on the string, handle the printing different */
  /* may use a switch-case? */
  fread( buf, 1, sizeof( buf ), in);
  printf( "%s\n", buf );

  fclose( in );
  
  return EXIT_SUCCESS;
}
