#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argv[1]){
/* set up html file name */
        char fileName[30];
        const char fileEnd[] = ".html";
        strcpy(fileName, argv[1]);
        strcat(fileName, fileEnd);

/* set up css file name*/
        char cssName[30];
        strcpy(cssName, argv[1]);
        strcat(cssName, ".css");

/*test if file already exists*/
       if(fopen(("%s", fileName), "r")){
        printf("File Already Exists. Canceling write.");
       }else {
/*create new files*/
        FILE * htmlPointer = fopen(("%s", fileName), "w");


        fclose(htmlPointer);

        FILE * cssPointer = fopen(("%s", cssName), "w");


        fclose(cssPointer);
       }
    } else {
        printf("Please provide a file name as the first argument.");
    }
    return 0;
}
