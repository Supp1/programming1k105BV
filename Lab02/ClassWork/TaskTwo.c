#include "Task.h"

//Дано три числа. Найти наибольшее и наименьшее
int TaskTwo( )
{
    int max = 0;
    int min = 0;
    int first_num = 0;
    int	second_num = 0;
    int third_num = 0;
    printf("Write three numbers\n");
    if (3 != scanf("%i %i %i", &first_num, &second_num, &third_num))
    {
        printf("Input Error");
        return -1;
    }
    if (first_num == second_num && first_num == third_num)
    {
        printf("All numbers are similar!\n");
        return 0;
    }
    else if (first_num > second_num && first_num > third_num)
    {
        max = first_num;
        if (second_num < third_num)
        {
            min = second_num;
        }
        else if (third_num < second_num)
        {
            min = third_num;
        }
    }
    else if (second_num > first_num && second_num > third_num)
    {
        max = second_num;
        if (first_num < third_num)
        {
            min = first_num;
        }
        else if (third_num < first_num)
        {
            min = third_num;
        }
    }
    else if (third_num > first_num && third_num > second_num)
    {
        max = third_num;
        if (second_num < third_num)
        {
            min = second_num;
        }
        else if (first_num < second_num)
        {
            min = first_num;
        }
    }
    else
    {
        printf("Some errors");
        return -1;
    }
    printf("%i - Maximal; %i - Minimal", max, min);
    return 0;
}
