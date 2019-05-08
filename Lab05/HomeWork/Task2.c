#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
#define SIGN(x) ((x) < 0 ? -1 : ((x) > 0 ? 1 : 0))
#define LIMIT 250

typedef double (*foo) (double);

double iteration (double, double, foo, foo, unsigned short);
double bisection (double, double, foo, foo, unsigned short);
double chord (double, double, foo, foo, unsigned short);
double tangent (double, double, foo, foo,  unsigned short);
double equation(double);
double diffEquation(double);

int TaskTwo()
{
    unsigned short id = 10;
    double lower_bound, upper_bound;
    unsigned short accuracy;
    printf("Lets write some data.\nWrite and separate with space numbers in this sequence: \n\tlower bound, upper bound, integer accuracy\n");
    if(3 != scanf("%lf %lf %d", &lower_bound, &upper_bound, &accuracy))
    {
        printf("ERROR IN INPUT");
        return -1;
    }
    double (*arr[4]) (double low_bound, double up_bound, foo f, foo df, unsigned short acc) = {iteration, bisection, chord, tangent};
    printf("What method do you want to use?\n\t[0]Iteration\n\t[1]Bisection\n\t[2]Chord\n\t[3]Tangent\n");
    scanf("%d", &id);
    if(id > 3){
        printf("Unknown operation");
        return -2;
    }
    double res = arr[id](0.2, 0.4, equation, diffEquation, 5);
    printf("%.4f", res);
    return 0;
}
double equation(double x)
{
    return sqrt(x) - 2 * cos(PI*2) * x;
}
double diffEquation(double x)
{
    return 1/2*sqrt(x) - 1;
}

double min (double num1, double num2)
{
    return(num1 < num2? num1: num2);
}

double max (double num1, double num2)
{
    return(num1>num2?num1: num2);
}

double iteration(double lower_bound,double upper_bound, foo f, foo df, unsigned short accuracy)
{
    printf("********************YOU CHOOSE ITERATION********************\n");
    double e = 1/pow(10, accuracy);
//  printf("Epsilon: %f\n", e);
    double x = lower_bound;
    for(; x < upper_bound-e; x+=e)
    {
        double y2 = f(lower_bound);
        double y1 = f(x+e);
        if((int)(y1*pow(10, accuracy)) == 0)
        {
            //printf("Function is Zero. The answer is:%f \n", x);
            continue;
        }
        //printf("X: %f\t Y:%f\n",x,y1);
        //printf("Y1: %d, Y2: %d, SIGNS %d\n",SIGN(y1), SIGN(y2), SIGN(y1) * SIGN(y2));
        if (SIGN(y1) * SIGN(y2) < 0)
        {
            //printf("Interval of decision: (%f;%f)\n", x-2*e, x-e);
            break;
        }
        y2 = y1;
    }
    return x;
}

double bisection (double lower_bound,double upper_bound, foo f, foo df, unsigned short accuracy)
{
    printf("********************YOU CHOOSE BISECTION********************\n");
    double e = 1/pow(10,accuracy);
    unsigned short count = 0;
    double central_point;
    while(fabs(upper_bound - lower_bound) > e)
    {
        central_point = (upper_bound + lower_bound)/2;
        //printf("CENTER: %f\n", central_point);
        double y_up = f(upper_bound);
        double y_low = f(lower_bound);
        double y_central = f(central_point);
        if (SIGN(y_up) == SIGN(y_central))
        {
            upper_bound = central_point;
        }
        else if(SIGN(y_low) == SIGN(y_central))
        {
            lower_bound = central_point;
        }
        else
        {
            return central_point;
        }
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            return central_point;
        }
    }
    return central_point;
}

double chord(double lower_bound,double upper_bound, foo f, foo df, unsigned short accuracy)
{
    printf("********************YOU CHOOSE CHORD***************************\n");
    double e = 1/pow(10, accuracy);
    unsigned short count = 0;
    double chord_point;
    while(fabs(upper_bound - lower_bound) > e)
    {
        chord_point = lower_bound - f(lower_bound) * ((upper_bound - lower_bound)/(f(upper_bound) - f(lower_bound)));
        double y_up = f(upper_bound);
        double y_low = f(lower_bound);
        double y_chord = f(chord_point);
        if(SIGN(y_up) == SIGN(y_chord))
        {
            upper_bound = chord_point;
        }
        else if(SIGN(y_low) == SIGN(y_chord))
        {
            lower_bound = chord_point;
        }
        else
        {
            return chord_point;
        }
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            return chord_point;
        }
    }
    return chord_point;
}

double tangent(double lower_bound,double upper_bound, foo f, foo df, unsigned short accuracy)
{
    printf("********************YOU CHOOSE TANGENT************************\n");
    double e = 1/pow(10, accuracy);
    double x0 = 0.2;
    printf("Print starting value(except zero)\n");
    scanf("%lf", &x0);
    if(x0 == 0)
    {
        printf("ERROR\n");
        return NAN;
    }
    double x1 = x0 - f(x0)/df(x0);
    unsigned short count = 0;
    while (fabs(x1 - x0) > e)
    {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
        if(count++ == LIMIT)
        {
            printf("There is %d iterations. Program was stopped\n", LIMIT);
            break;
        }
    }
    return x1;
}
