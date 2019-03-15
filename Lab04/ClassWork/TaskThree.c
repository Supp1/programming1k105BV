#include "../myString.h"

int TaskThree()
{
    //probability for 1 character = 13/32 (ONLY ASCII TABLE)
    //probability for n characters = n * 13/32
    const double pAlpha = 13.0f/32.0f;
    char string[SIZE];
    if(NULL == *gets(string))
    {
        printf("ERROR. Input can't be empty");
        return -1;
    }
    printf("Probability of presence alphabet symbols for %d characters is %.3f", strlen(string), strlen(string) * pAlpha);
    return 0;
}
