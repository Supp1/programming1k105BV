#include "Lab.h"

int LabPart1(void)
{
    printf("Function value by pow sequence\n\n");
    const double PI = 3.14;
    double sum;
    int N = 7;
    double upper_bound = 9 * PI / 5;
    double lower_bound = PI / 5;
    double step = (upper_bound - lower_bound) / (N - 1);
    for (double x = lower_bound; x <= upper_bound; x += step)
    {
        double sum_term = cos(x);//When n = 1;
        sum = 0;
        for (int n = 1; n <= N; n++)
        {
            sum += sum_term;
            sum_term *= n * (cos(x) - tan(n*x) * sin(x)) / (n + 1);
        }
        double y = F(x);
        printf("X = %.5f\n\tResult of Sum: %f\n",x, sum);
        printf("\tResult of function: %f\n", y);
        double tolerance = fabs(y - sum);
        printf("\tTolerance: %f\n", tolerance);
    }
    return 0;
}

int LabPart2(void)
{
    printf("Tabulated function with 1 variable\n\n");
    float lower_bound = -3.0f;
    float upper_bound = 3.0f;
    float step = 0.1f;
    double y = 0.0;
    double x = 0.0;
    printf("X:\t");
    for (x = lower_bound; x < upper_bound + 0.1; x += step)
    {
        printf("%.2f\t", x);
    }
    printf("\n\nY:\t");
    for (x = lower_bound; x < upper_bound + 0.1; x += step)
    {
        double y = CONDITION1(x) ? FUNC1(x) : (CONDITION2(x) ? FUNC2(x) : FUNC3(x));
        printf("%.2f\t", y);
    }
    printf("\n");

    printf("*******PART 2***********\n");

    printf("Tabulated function with 2 variables\n\n");
    double x_1 = 0.0;
    double y_1 = 0.0;
    float step_x = 1;
    float step_y = 2;
    float lower_bound_x = -2.0f;
    float upper_bound_x = 2.0f;
    float lower_bound_y = -4.0f;
    float upper_bound_y = 4.0f;
    printf("Y|X\t");
    for (x_1 = lower_bound_x; x_1 < upper_bound_x + 0.1; x_1 += step_x)
    {
        char sign = x_1 + step_x <= upper_bound_x ? '\t' : '\n';
        printf("%.1f%c", x_1,sign);
    }
    for (y_1 = lower_bound_y; y_1 < upper_bound_y + 0.1; y_1 += step_y)
    {
        printf("%.1f\t", y_1);
        for (x_1 = lower_bound_x; x_1 < upper_bound_x + 0.1; x_1 += step_x)
        {
            char sign = x_1 + step_x <= upper_bound_x ? '\t' : '\n';
            double z = x_1 * y_1 * (x_1 - y_1);
            printf("%.1f%c", z, sign);
        }
    }
    return 0;
}
