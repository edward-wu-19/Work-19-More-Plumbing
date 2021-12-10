#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/stat.h>

#define LEN 1024

int main(){
    int pToC = open("pToC", O_RDONLY);
    int cToP = open("cToP", O_WRONLY);

    char line[LEN];

    // printf("A\n");

    while (1){
        read(pToC, line, LEN);

        char* tmp = line;
        int i = 0;
        while (i < LEN){
            *tmp = toupper(*tmp);
            tmp++;
            i++;
        }

        write(cToP, line, LEN);
    }

    return 0;
}