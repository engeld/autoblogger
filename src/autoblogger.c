#include <stdio.h>
#include <errno.h>

int main(void)
{
    char        item[], status;
    FILE        *fp;

    if((fp = fopen("P:\\links.txt", "r+")) == NULL) {
        printf("No such file\n");
        exit(1);
    }

    while(1) {
        int ret = fscanf(fp, "%s %c", item, &status);
        if(ret == 2) {
            printf("\n%s \t %c", item, status);
        } else if(errno != 0) {
            perror("scanf: ");
            break;
        } else if(ret == EOF) {
            break;
        } else {
            printf("No match!\n");
        }
    }
    printf("\n");
    if(feof(fp)) {
        puts("EOF");
    }
    return 0;
}
