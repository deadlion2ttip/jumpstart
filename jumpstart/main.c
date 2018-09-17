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
        char html[255];
        char css[255];

        printf("Opening templates\n");
        FILE * htmlTemplate = fopen("C:/Users/cigma/code/playing around/C/jumpstart/jumpstart/template.html", "r");
        FILE * cssTemplate = fopen("C:/Users/cigma/code/playing around/C/jumpstart/jumpstart/template.css", "r");
/* fgets stops on newline. create a loop that reads template line by line to a variable, then concatinates that variable at every line read to a master variable that is then written to the new file.*/

        printf("Creating new files\n");
        FILE * htmlPointer = fopen(("%s", fileName), "w");
        FILE * cssPointer = fopen(("%s", cssName), "w");

        int i = 1;

        printf("Copying html template to new .html\n");
       while(i < 32) {
        fgets(html, 255, htmlTemplate);
        fprintf(htmlPointer,"%s", html);
        i ++;
        };

        int j = 1;
        printf("Copying css template to new .css\n");
        while(j < 6) {
        fgets(css, 255, cssTemplate);
        fprintf(cssPointer,"%s", css);
        j ++;
        };


        fclose(htmlTemplate);
        fclose(cssTemplate);

        fclose(htmlPointer);
        fclose(cssPointer);

        printf("Done!\n");
       }
    } else {
        printf("Please provide a file name as the first argument.");
    }
    return 0;
}
