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
    mkfifo("pToC", 0644);
    mkfifo("cToP", 0644);

    int pToC = open("pToC", O_WRONLY);
    int cToP = open("cToP", O_RDONLY);

    char line[LEN];

    while (1){
        fgets(line, LEN, stdin);

        write(pToC, line, LEN);

        read(cToP, line, LEN);
        printf("The child says: \n%s\n", line);
    }

    return 0;
}