#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
    char        item[] = "", status;
    FILE        *fp;

    if((fp = fopen("./links.txt", "r+")) == NULL) {
        printf("No such file\n");
        exit(1);
    }

    while(1) {
        int ret = fscanf(fp, "%s", item);
        if(ret == 1) {
            printf("\n%s", item);
        } else if(errno != 0) {
            perror("scanf: ");
            break;
        } else if(ret == EOF) {
            break;
        } else {
            printf("No match!, retcode: %i\n", ret);
        }
    }
    printf("\n");
    if(feof(fp)) {
        puts("EOF");
    }
    return 0;
}
