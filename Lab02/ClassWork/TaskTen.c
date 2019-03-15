#include "Task.h"

int TaskTen()
{
    int user_number = 0;
    unsigned int result = 1;
    printf("Write number to count factorial\n\n");
    if (1 != scanf("%i", &user_number))
    {
        printf("Input Error");
    }
    for (; user_number > 1; user_number--)
    {
        result *= user_number;
    }
    printf("Result: %i", result);
    return 0;
}
