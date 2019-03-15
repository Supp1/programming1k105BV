#include "Task.h"

//Определить лежит ли точка М в треугольнике АBC по координатам
int TaskSeven(void)
{
    int a_x = 3;
    int a_y = 1;
    int b_x = 5;
    int b_y = 5;
    int c_x = 8;
    int c_y = 1;
    int user_x = 0;
    int user_y = 0;
    printf("Write coordinates of your point. View: (x;y)\n\n");
    if (2 != scanf("(%i;%i)", &user_x, &user_y))
    {
        printf("Input Error");
        return -1;
    }
    int side_one = (user_x - a_x) * (b_y - a_y) - (user_y - a_y) * (b_x - a_x);
    int side_two = (user_x - b_x) * (c_y - b_y) - (user_y - b_y) * (c_x - b_x);
    int side_three = (user_x - c_x) * (a_y - c_y) - (user_y - c_y) * (a_x - c_x);
    if ((side_one < 0 && side_two < 0 && side_three < 0) || (side_one > 0 && side_two > 0 && side_three > 0))
    {
        printf("Your point is inside of triangle\n");
    }
    else
    {
        printf("Your point is outside of triangle\n");
    }
    return 0;
}
