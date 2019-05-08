#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FUNC1(x) (x) * (x) - 1
#define FUNC2(x) (x) * exp(-((x)*(x)))
#define FUNC3(x) (x) * (x) * (x) - (x) + 1

int TaskOne()
{
    FILE *file = fopen("test.txt", "w");
    fprintf(file, "Tabulated function with 1 variable\n\n");
    fclose(file);
    file = fopen("test.txt", "a");
    float lower_bound = -3.0f;
    float upper_bound = 3.0f;
    float step = 0.1f;
    double y = 0.0;
    double x = 0.0;
    fprintf(file, "X:\t");
    for (x = lower_bound; x < upper_bound + 0.1; x += step)
    {
        fprintf(file, "%.2f\t", x);
    }
    fprintf(file, "\n\nY:\t");
    for (x = lower_bound; x < upper_bound + 0.1; x += step)
    {
        double y = (x <= 2) ? FUNC1(x) : (x > -2 && x <= 2) ? FUNC2(x) : FUNC3(x);
        fprintf(file, "%.2f\t", y);
    }
    fprintf(file, "\n\n");

    fprintf(file, "*******PART 2***********\n");

    fprintf(file, "Tabulated function with 2 variables\n\n");
    double x_1 = 0.0;
    double y_1 = 0.0;
    float step_x = 1;
    float step_y = 2;
    float lower_bound_x = -2.0f;
    float upper_bound_x = 2.0f;
    float lower_bound_y = -4.0f;
    float upper_bound_y = 4.0f;
    fprintf(file, "Y|X\t");
    for (x_1 = lower_bound_x; x_1 < upper_bound_x + 0.1; x_1 += step_x)
    {
        //PRINT POSSIBLE X VALUES
        char sign = x_1 + step_x <= upper_bound_x ? '\t' : '\n';
        fprintf(file, "%.1f%c", x_1,sign);
    }
    for (y_1 = lower_bound_y; y_1 < upper_bound_y + 0.1; y_1 += step_y)
    {
        //PRINT POSSIBLE Y VALUES
        fprintf(file, "%.1f\t", y_1);
        for (x_1 = lower_bound_x; x_1 < upper_bound_x + 0.1; x_1 += step_x)
        {
            //PRINT RESULT
            char sign = x_1 + step_x <= upper_bound_x ? '\t' : '\n';
            double z = x_1 * y_1 * (x_1 - y_1);
            fprintf(file, "%.1f%c", z, sign);
        }
    }
    fclose(file);
    return 0;
}
