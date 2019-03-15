#include "Task.h"

//ќпределить лежит ли точка в пересечении кругов
int TaskOne(void)
{
    float x = 0.0f;
    float y = 0.0f;
    printf("Write coordinats of point M. View: (x;y)\n");
    if (2 != scanf("(%f;%f)", &x, &y))
    {
        printf("Input Error");
        return -1;
    }
    double functionFirst = x * x + y * y;
    double functionSecond = pow(x + 1, 2) + y * y;
    if (functionFirst <= 1 && functionSecond <= 1)
    {
        printf("Point M is INSIDE of circle intersection\n\n");
    }
    else
    {
        printf("Point M is OUTSIDE of Circle intersection");
    }
    return 0;
}
