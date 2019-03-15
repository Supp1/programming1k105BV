#include "../Array.h"
#include <math.h>
int LabFirst()
{
    //INITIALIZING
    int sum1 = 0, sum2 = 0, differ = 0, temp;
    const int length = 6;
    int* array = calloc(length, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < length; ++i)
    {
        *(array + i) = rand() %31 - 10;
    }
    int* startArray = calloc(length, sizeof(int));
    for (int i = 0; i < length; ++i)
    {
        *(startArray + i) = *(array + i);
    }
    //SOME ACTIONS
    for(int a = 0; a < length / 2; ++a)
    {
        sum1 += *(array+a);
    }
    for(int a = length/2; a < length; ++a)
    {
        sum2 += *(array+a);
    }
    differ = abs(sum1 - sum2);
    printf("SOURCE DATA\nSum1: %d\tSum2: %d\tDiffer: %d\nSource Array:     ", sum1, sum2, differ);
    SHOW_ARRAY(length, array);
    printf("Copy of Source:   ");
    SHOW_ARRAY(length, startArray);
    //MAIN PART
    printf("\n\n___________________EXECUTING MAIN PART___________________\n");
    sum1 = 0;
    sum2 = 0;
    for(int left = 0; left < length/2; ++left)
    {
        for(int right = length - 1; right >= length / 2; --right)
        {
            temp = *(array + left);
            *(array + left) = *(array + right);
            *(array + right) = temp;
            for(int a = 0; a < length / 2; ++a)
            {
                sum1 += array[a];
            }
            for(int a = length/2; a < length; ++a)
            {
                sum2 += array[a];
            }
            if(abs(sum1 - sum2) < differ || 0 == sum1 - sum2)
            {
                printf("Breaking \"j\" part\n");
                differ = abs(sum1 - sum2);
                for(int a = 0; a < length; ++a)
                {
                    *(startArray + a) = *(array + a);
                }
                printf("NEW DATA:\nSum1: %d\tSum2: %d\tDiffer:%d\nSource Array:     ",sum1, sum2, differ);
                SHOW_ARRAY(length,array);
                printf("Copy of Source:   ");
                SHOW_ARRAY(length, startArray);
                break;
            }
            else
            {
                printf("Continue\"j\" part\n");
                printf("DATA NOT CHANGED:\nSum1: %d\tSum2: %d\tPrev Differ: %d\nSource Array:     ",sum1, sum2, differ);
                SHOW_ARRAY(length,array);
                printf("Copy of Source:   ");
                SHOW_ARRAY(length, startArray);
                for(int a = 0; a < length; ++a)
                {
                    *(array + a) = *(startArray + a);
                }
                sum1 = 0;
                sum2 = 0;
            }
        }
    }
    free(array);
    printf("___________RESULT____________\n");
    SHOW_ARRAY(length, startArray);
    free(startArray);
    return 0;
}
