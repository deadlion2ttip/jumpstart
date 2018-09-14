#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat(char *dest, const char *src);


int main(int *argc, char *argv[])
{
    if (argv[1]){

        char fileName[30];
        char fileEnd[] = ".html";
        strcpy(fileName, argv[1]);
        strcat(fileName, fileEnd);
        printf("%s", fileName);


       if(fopen(("%s", fileName), "r")){
        printf("File Already Exists. Canceling write.");
       }else {

        FILE * fpointer = fopen(("%s", fileName), "w");


        fclose(fpointer);
       }
    } else {
        printf("Please provide a file name as the first argument.");
    }
    return 0;
}
