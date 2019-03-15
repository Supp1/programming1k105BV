#include "../myString.h"

int TaskFive()
{
    char string[SIZE];
    if(NULL == *gets(string))
    {
        printf("ERROR. Input can't be empty");
        return -1;
    }
    if(!(strchr(string, '(')||strchr(string, ')')||
       strchr(string, '[')||strchr(string, ']')||
       strchr(string, '{')||strchr(string, '}')))
    {
        printf("ERROR. There isn't any brackets\n");
        return -2;
    }

    char changString[strlen(string) + 1];
    removeCorrectBrackets(changString, string);
    puts(changString);
    if(strchr(changString, '(')||strchr(changString, ')')||
       strchr(changString, '[')||strchr(changString, ']')||
       strchr(changString, '{')||strchr(changString, '}'))
    {
        printf("WRONG BRACKETS\n");
    }
    else
    {
        printf("Correct brackets\n");
    }
    return 0;
}

void removeCorrectBrackets(char* stringOut,char* stringIn)
{
    char replacement = '*';
    strcpy(stringOut, stringIn);
    for(int i = 0; i < strlen(stringOut); ++i)
    {
        if(*(stringOut + i) == '(')
        {
            if(strrchr(stringOut + i,')'))
            {
                *(stringOut + i) = replacement;
                *(strchr(stringOut + i,')')) = replacement;
                continue;
            }
            else
            {
                break;
            }
        }
        if(*(stringOut + i) == '[')
        {
            if(strrchr(stringOut + i,']'))
            {
                *(stringOut + i) = replacement;
                *(strchr(stringOut + i,']')) = replacement;
                continue;
            }
            else
            {
                break;
            }
        }
        if(*(stringOut + i) == '{')
        {
            if(strrchr(stringOut + i,'}'))
            {
                *(stringOut + i) = replacement;
                *(strchr(stringOut + i,'}')) = replacement;
                continue;
            }
            else
            {
                break;
            }
        }
    }
}
