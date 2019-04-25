#include <stdio.h>
#include <stdlib.h>
#define LEN 6
int TaskOne()
{
    int x = 1;
    int array[LEN] = {5,4,3,2,1,7};
    Sort(array);
    int upper_bound = LEN;
    int lower_bound = 0;
    for(int i = 0; i < LEN; ++i)
    {
        printf("%d ", array[i]);
    }
    int count = 0;
    printf("\n");
    while(1)
    {
        printf("%d try\n", count);
        ++count;
        if(array[upper_bound/2 + lower_bound] > x)
        {
            printf("UPPER: %d\tELEMENT: %d \n", upper_bound, array[upper_bound/2 + lower_bound]);
            upper_bound = upper_bound/2 + lower_bound;
        }
        else if (array[upper_bound/2 + lower_bound] < x)
        {
            printf("LOWER: %d\n", upper_bound);
            lower_bound = upper_bound/2 + lower_bound;
        }
        else if (array[upper_bound/2 + lower_bound] == x)
        {
            printf("Element is under %d id", upper_bound/2 + lower_bound);
            break;
        }
        if(count == 50)
        {
            break;
        }
    }
    return 0;
}

void Sort(int *array)
{
    int check = 1;
    int temp;
    while(check)
    {
        check = 0;
        for(int i = 0; i < 5; ++i)
        {
            if(array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                check = 1;
            }
        }
    }
}
