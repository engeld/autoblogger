#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "html.h"

int main( int argc, char *argv[] )
{
  FILE    *in;
  int     character;
  int     counter;

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

  OutputHTMLHeader();

  /* loop through input file and process (depending on content) */
  for(counter = 0; (character=getc(in)) != EOF; counter++){
    /* printf( "%c", character); */

    switch( character ){
    case '=':  /* all characters until the first equal sign belongs to the title */
      printf( "<h1>" );
      /* empty the char-bucket */
      printf( "</h1>\n" );
      break;
    case '-':
      printf( "<h2>" );
      /* empty the char-bucket */
      printf( "</h2>\n" );
      break;
    case '\n': /* 2 newlines => new section */
      if( getc(in) == '\n'){
        printf( "<p>" );
        /* empty the bucket (loop through the links in it) */
        printf( "</p>\n" );
      }
      break;
    default:
      /* printf( "%c", ch); */
      /* add char to bucket */
      break;
    }
  }

  fclose( in );

  OutputHTMLFooter();
  return EXIT_SUCCESS;
}
