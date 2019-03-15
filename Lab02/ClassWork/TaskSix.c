#include "Task.h"

//Определить тип треугольника
int TaskSix(void)
{
    int user_side_one, user_side_two, user_side_three; //sides of triangle
    user_side_one = user_side_two = user_side_three = 0;
    printf("Write Sides of triangle\n");
    if (3 != scanf("%i %i %i", &user_side_one, &user_side_two, &user_side_three))
    {
        printf("Input Error");
        return -1;
    }
    int side_max = fmax(user_side_one, fmax(user_side_two, user_side_three));
    int side_one = fmin(user_side_one, fmin(user_side_two, user_side_three));
    int side_two = (user_side_one + user_side_two + user_side_three) - (side_one + side_max);

    if (side_one + side_two <= side_max || side_max + side_two <= side_one || side_max + side_one <= side_two)
    {
        printf("Error! This triangle doesn't exist");
        return -2;
    }
    if (side_one == side_two && side_one == side_max)
    {
        printf("This is equilateral triangle\n");//равносторонний
        return 0;
    }
    if (side_one == side_two || side_one == side_max || side_two == side_max)
    {
        printf("This is isosceles triangle\n");//равнобедренный
    }
    else
    {
        printf("This is versatile triangle\n");//разносторонний
    }
    if (side_max * side_max == side_one * side_one + side_two * side_two)
    {
        printf("This is right triangle\n");//Прямоугольный
    }
    else if (side_max * side_max < side_one * side_one + side_two * side_two)
    {
        printf("This is obtuse triangle\n");//Тупоугольный
    }
    else if (side_max * side_max > side_one * side_one + side_two * side_two)
    {
        printf("This is acute triangle\n");//Остроугольный
    }
    return 0;
}
