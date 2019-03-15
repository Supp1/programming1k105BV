#include "../myString.h"

int TaskOne()
{
    char word[SIZE];
    if(NULL == *gets(word))
    {
        printf("ERROR. Input can't be empty");
        return -1;
    }
    char* symbol = word;
    int count = 1;
    char replacement = '*';
    for(; *symbol&&!isspace(*symbol); ++symbol)
    {
        if(strrchr(word,*symbol)!= symbol && *symbol != replacement)
        {
            char* checkSymbol = symbol + 1;
            for(; *checkSymbol&&!isspace(*checkSymbol); ++checkSymbol)
            {
                if(*checkSymbol == *symbol)
                {
                    ++count;
                    word[checkSymbol - word] = replacement;
                }
            }
            printf("Letter %c is repeating %d times\n\n", *symbol, count);
            count = 0;
        }
        else if(*symbol != replacement)
        {
            printf("Letter %c NOT repeating\n\n", *symbol);
        }
    }
    return 0;
}
