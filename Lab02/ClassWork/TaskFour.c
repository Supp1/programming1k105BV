#include "Task.h"

//ќпределить простоту числа с помощью "–ешета Ёратосфена"
int TaskFour(void)
{
    int check = 0;
    int user_number = 2;
    printf("Write any number\n");
    if (1 != scanf("%d", &user_number))
    {
        printf("Input Error");
        return -1;
    }
    for (int i = 2; i < user_number; i++)
    {
        if (0 == user_number % i)
        {
            check = 1;
            break;
        }
    }
    check ? printf("This number is not simple\n") : printf("This number is simple\n");
    return 0;
}
