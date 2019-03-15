#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double const E = 2.71828;
    double x = 0.0, a = 0.0, b = 0.0;
    printf("Type values\n");
    printf("\tx:");
    if(1 != scanf("%lf", &x))
    {
        printf("WRONG VALUE");
        return -1;
    }
    printf("\ta:");
    if(1 != scanf("%lf", &a))
    {
        printf("WRONG VALUE");
        return -1;
    }
    printf("\tb:");
    if(1 != scanf("%lf", &b)){
          printf("WRONG VALUE");
          return -1;
    }
    double result = pow(x,b*x) / pow(E, -a * x);
    printf("%Result is: .5f",result);
    return 0;
}
