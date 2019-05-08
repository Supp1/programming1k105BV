#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Task1.c"
#include "Task2.c"
int TaskOne(void);
int TaskTwo(void);
int main()
{
    unsigned short id = 0;
    printf("Choose task.\n\t[1]Task1. Tabulation in file\n\t[2]Task2. Replacing word\n");
    scanf("%d", &id);
    switch(id)
    {
        case 1:
            return TaskOne();
        case 2:
            fflush(stdin);
            return TaskTwo();
        default:
            printf("Something wrong");
            break;
    }
    return 0;
}
