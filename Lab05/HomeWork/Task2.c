#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
#define SIGN(x) ((x) < 0 ? -1 : 1)
#define DERFUNC(x) (1/2*sqrt(x) - 1)
#define LIMIT 250
void iteration (void);
void bisection (void);
void chord (void);
void tangent (void);
typedef void (*func) (void);
int TaskTwo()
{
    unsigned short id = 10;
    void (*arr[4]) (void) = {iteration, bisection, chord, tangent};
    printf("What method do you want to use?\n\t[0]Iteration\n\t[1]Bisection\n\t[2]Chord\n\t[3]Tangent\n");
    scanf("%d", &id);
    if(id > 3){
        printf("Unknown operation");
        return -1;
    }
    arr[id]();
    return 0;
}
double foo (x)
{
    return (sqrt(x) - 2*cos(PI*2)*x)
}

double min (double num1, double num2)
{
    return(num1 < num2? num1: num2);
}

double max (double num1, double num2)
{
    return(num1>num2?num1: num2);
}

void iteration()
{
    unsigned short accuracy;
    double lower_bound = 0.2;
    double upper_bound = 0.4;
    printf("Print accuracy:  ");
    if(1 != scanf("%d", &accuracy))
    {
        printf("ERROR");
        return;
    }
    printf("Print lower and upper bounds. Print any letter to leave standard values\n");
    scanf("%lf %lf", &lower_bound, &upper_bound);
    double e = 1/pow(10, accuracy);
//  printf("Epsilon: %f\n", e);
    double y2 = FUNC(lower_bound);
    for(double x = lower_bound+e; x < upper_bound; x+=e)
    {
        double y1 = FUNC(x);
        if((int)(y1*pow(10, accuracy)) == 0)
        {
            //printf("Function is Zero. The answer is:%f \n", x);
            continue;
        }
        //printf("X: %f\t Y:%f\n",x,y1);
        //printf("Y1: %d, Y2: %d, SIGNS %d\n",SIGN(y1), SIGN(y2), SIGN(y1) * SIGN(y2));
        if (SIGN(y1) * SIGN(y2) < 0)
        {
            printf("Interval of decision: (%f;%f)\n", x-2*e, x-e);
            break;
        }
        y2 = y1;
    }
}

void bisection ()
{
    unsigned short accuracy;
    double upper_bound = 100.0;
    double lower_bound = 0.0;
    printf("Print accuracy:  ");
    if(1 != scanf("%d", &accuracy))
    {
        printf("ERROR");
        return;
    }
    printf("Print lower and upper bounds. Print any letter to leave standard values\n");
    scanf("%lf %lf", &lower_bound, &upper_bound);
    double e = 1/pow(10,accuracy);
    double y2 = FUNC(lower_bound);
    unsigned short count = 0;
    while(fabs(upper_bound - lower_bound) > e)
    {
        if(FUNC((upper_bound + lower_bound)/2) > 0)
        {
            lower_bound = (upper_bound + lower_bound)/2;
        }
        else if (FUNC((upper_bound + lower_bound)/2) < 0)
        {
            upper_bound = (upper_bound + lower_bound)/2;
        }
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            break;
        }
    }
    printf("Interval of decision: (%f;%f)\n", lower_bound, upper_bound);
}

void chord()
{
    unsigned short accuracy;
    double upper_bound = 0.8;
    double lower_bound = 0.1;
    printf("Print accuracy:  ");
    if(1 != scanf("%d", &accuracy))
    {
        printf("ERROR");
        return;
    }
    printf("Print lower and upper bounds. Print any letter to leave standard values\n");
    scanf("%lf %lf", &lower_bound, &upper_bound);
    double e = 1/pow(10, accuracy);
    unsigned short count = 0;
    while(fabs(upper_bound - lower_bound) > e)
    {
        double x = lower_bound - FUNC(lower_bound) * ((upper_bound - lower_bound)/(FUNC(upper_bound) - FUNC(lower_bound))) ;
        if(FUNC(x) > 0)
        {
            lower_bound = x;
        }
        else if(FUNC(x) < 0)
        {
            upper_bound = x;
        }
        //printf("%lf\n", FUNC(x));
        //printf("%lf\n", x);
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            break;
        }
    }
    printf("Interval of decision: (%f;%f)\n", lower_bound, upper_bound);
}

void tangent()
{
    unsigned short accuracy;
    printf("Print accuracy:  ");
    if(1 != scanf("%d", &accuracy))
    {
        printf("ERROR");
        return;
    }
    double e = 1/pow(10, accuracy);
    double x0 = 0.2;
    double x1 = x0 - FUNC(x0)/DERFUNC(x0);
    unsigned short count = 0;
    while (fabs(x1 - x0) > e)
    {
        x0 = x1;
        x1 = x0 - FUNC(x0) / DERFUNC(x0);
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            break;
        }
    }
    printf("Interval of decision: (%f;%f)\n", x0, x1);
}


#define FUNC(x) (sqrt(x) - 2 * cos(PI*2) * (x))
