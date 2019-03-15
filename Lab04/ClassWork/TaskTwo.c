#include "../myString.h"

int TaskTwo()
{
    char word[SIZE];
    if(NULL == *gets(word))
    {
        printf("ERROR. Input can't be empty");
        return -1;
    }
    for(int i = 0; i < strlen(word); ++i)
    {
        if(isalpha(*(word + i)))
        {
            if (i + 1 == strlen(word))
            {
                printf("This string is a word");
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("%dThis string isn't a word\n",i);
            printf("%c",word[i]);
            break;
        }
    }
    return 0;
}
