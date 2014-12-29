#include <stdio.h>
#include "html.h"

void OutputHTMLHeader(void){
  puts("<!DOCTYPE html>");
  puts("<html>");
  puts("<head>");
  puts("  <title>Linkliste</title>");
  puts("</head>");
  puts("<body>");
}

void OutputHTMLFooter(void){
  puts("</body>");
  puts("</html>");
}
