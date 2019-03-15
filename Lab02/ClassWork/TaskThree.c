#include "Task.h"

int TaskThree(void)
{
    int first_number = 0;
    int second_number = 0;
    int temp = 0;
    int a = 1;
    printf("Write two number, to find lowest common divisor");
    if (2 != scanf("%i %i", &first_number, &second_number))
    {
        printf("Input Error");
        return -1;
    }
    if ((first_number < 0 && second_number > 0) || (second_number < 0 && first_number > 0))
    {
        a = -1;
    }
    first_number = fabs(first_number);
    second_number = fabs(second_number);
    while (0 != first_number && 0 != second_number)
    {
        while (first_number >= second_number)
        {
            first_number -= second_number;
        }
        if (0 == first_number)
        {
            break;
        }
        temp = first_number;
        first_number = second_number;
        second_number = temp;
    }
    printf("NOD: %i \n\n", a*second_number);
    return 0;
}
