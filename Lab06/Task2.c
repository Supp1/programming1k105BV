#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int TaskTwo()
{
    char fileDest[] = "Task2.txt";
    char *input = malloc(20);
    char *change = malloc(20);
    char  *sent  = (char*)malloc(1000);
    memset(sent, NULL, 1000);
    memset(input, NULL, 20);
    memset(change, NULL, 20);
    FILE *srcFile = fopen(fileDest, "r");
    if(!srcFile)
    {
        printf("ERROR. Can't found file");
        return -1;
    }
    printf("Source file:\n");
    show(fileDest);
    fgets(sent, 500, srcFile);
    if(fclose(srcFile))
    {
        printf("ERROR. Can't close the file");
        return -2;
    }
    printf("What word we should find?\n");
    gets(input);
    printf("Print replacer\n");
    gets(change);
    strcat(change, " ");
    replace(sent, input, change);
    free(input);
    free(change);
    srcFile = fopen(fileDest, "w");
    fputs(sent, srcFile);
    if(fclose(srcFile))
    {
        printf("ERROR. Can't close the file");
        return -2;
    }
    free(sent);
    printf("Result is:\n");
    show(fileDest);
    return 0;
}


void replace (char* sent, char* find, char* change)
{
    unsigned short count = 0;
    while(sent=strstr(sent,find) )
    {
        if(count++ == 100)
        {
            printf("Ouch. Too much iterations");
            break;
        }
        memmove(sent + strlen(change),sent+strlen(find)+1,1+strlen(sent+strlen(find)));
        memmove(sent,change,strlen(change));
    }
}

void show (char* fileDest)
{
    char str[100];
    FILE *f = fopen(fileDest, "r");
    while(fgets(str, 100, f))
    {
        printf("%s", str);
    }
    fclose(f);
    printf("\n\n");
}
