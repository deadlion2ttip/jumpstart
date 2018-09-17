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
/*copy template files*/
        char html[2000];
        char css[200];

        FILE * htmlTemplate = fopen("C:/Users/cigma/code/playing around/C/jumpstart/jumpstart/template.html", "r");
        FILE * cssTemplate = fopen("C:/Users/cigma/code/playing around/C/jumpstart/jumpstart/template.css", "r");
/* fgets stops on newline. create a loop that reads template line by line to a variable, then concatinates that variable at every line read to a master variable that is then written to the new file.*/
        fgets(html, 2000, htmlTemplate);
        fgets(css, 200, cssTemplate);

        printf("%p", htmlTemplate);

        fclose(htmlTemplate);
        fclose(cssTemplate);

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
