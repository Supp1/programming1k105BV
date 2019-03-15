#include "../myString.h"

int TaskFour()
{
    int count = 0;
    char string[SIZE];
    if(NULL == *gets(string))
    {
        printf("ERROR. Input can't be empty");
        return -1;
    }
    for(int i = 0; i < strlen(string); ++i)
    {
        if(*(string + i) == '.')
        {
            ++count;
        }
    }
    printf("In this string %d sentences", count);
    return 0;
}
