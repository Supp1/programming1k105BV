#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UPPER 4
#define LOWER 2
//#define AMOUNT 10
/*INTEGRATE 3*sqrt(x) FROM 2 TO 9. EPSILON = 10^-4 */

double condition(double);
double trapeze (double step, double lower, double upper, double (*foo) (double));
double parab (double step, double lower, double upper, double (*foo) (double));
double centrRectangle(double step, double lower, double upper, double (*foo) (double));
double leftRectangle(double step, double lower, double upper, double (*foo) (double));
double rightRectangle(double step, double lower, double upper, double (*foo) (double));

int TaskThree()
{
    unsigned short accuracy = 4;
    double lower_bound = 2.0;
    double upper_bound = 9.0;
    printf("Lets write some data.\nWrite and separate with space numbers in this sequence: \n\tlower bound, upper bound, integer accuracy\n");
    if(3 != scanf("%lf %lf %d", &lower_bound, &upper_bound, &accuracy))
    {
        printf("ERROR IN INPUT");
        return -1;
    }
    double step = 1/pow(10, accuracy);
    unsigned short id = 0;
    double (*arr[5]) (double step, double lower, double upper, double (*foo) (double)) = {trapeze, parab, centrRectangle, leftRectangle, rightRectangle};
    printf("What method do you want to use?\n\t[0]Trapeze\n\t[1]Parabol\n\t[2]Central Rectangle\n\t[3]Left Rectangle\n\t[4]Right Rectangle\n");
    scanf("%d", &id);
    if(id > 4)
    {
        printf("ERROR");
        return -1;
    }
    double a = arr[id](step, lower_bound, upper_bound, condition);
    printf("Result is:  %f\n", a);
    return 0;
}

double condition(double x)
{
    return 3*sqrt(x);
}

double trapeze (double step, double lower, double upper, double (*foo) (double))
{
    int amount = ceil((upper - lower) / step);
    //printf("%d\n", amount);
    double sum = 0;
    for(int i = 1; i < amount; ++i)
    {
        //printf("%d      %f\n", i, lower + i*step);
        sum+=foo(lower+i*step);
    }
    double res = (step/2) * (2*sum + foo(lower) + foo(upper));
    return res;
}
double parab (double step, double lower, double upper, double (*foo) (double))
{
    double res = 0;
    int amount = ceil((upper - lower)/step);
    //printf("%d\n", amount);
    //COUNTING RESULT
    double sum1 = 0;
    for(int i = 1; i <= amount; i+=2)
    {
        //printf("%d\n", i);
        sum1 += foo(lower + i * step);
    }
    double sum2 = 0;
    for(int i = 2; i < amount; i+=2)
    {
        //printf("%d\n", i);
        sum2 += foo(lower + i * step);
    }
    res = step/3 * (foo(lower) + 4 * sum1 + 2 * sum2 + foo(upper));
    return res;
}

double centrRectangle(double step, double lower, double upper, double (*foo) (double))
{
    int amount = ceil((upper - lower) / step);
    //printf("%d\n", amount);
    double sum = 0;
    for(int i = 1; i <= amount; ++i)
    {
        //printf("%d\n", i);
        sum += foo(lower + step * (i-0.5));
    }
    sum *= step;
    //printf("%f", sum);
    return sum;
}

double leftRectangle(double step, double lower, double upper, double (*foo) (double))
{
    int amount = ceil((upper - lower) / step);
    //printf("%d\n", amount);
    double sum = 0;
    for(int i = 0; i < amount; ++i) {
        //printf("%d\n", i);
        sum += foo(lower+i*step);
    }
    sum *= step;
    //printf("%f", sum);
    return sum;
}

double rightRectangle(double step, double lower, double upper, double (*foo) (double))
{
    int amount = ceil((upper - lower) / step);
    //printf("%d\n", amount);
    double sum = 0;
    for(int i = 1; i <= amount; ++i) {
        //printf("%d\n", i);
        sum += foo(lower+i*step);
    }
    sum *= step;
    //printf("%f", sum);
    return sum;
}
