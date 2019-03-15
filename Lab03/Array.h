#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define SHOW_ARRAY(length, array)\
{\
    for (int i = 0; i < (length); i++){\
        printf("%d  ", *(array + i));\
    }\
    printf("\n");\
}
#define INITIALIZE_ARRAY(length, array, maxRandValue)\
{\
    srand(time(NULL));\
    for (int i = 0; i < (length); i++){\
        *(array + i) = rand() % (maxRandValue + 1);\
    }\
}

#define INITIALIZE_DYNAMIC_ARRAY(length, array, maxRandValue)\
{\
    array = malloc(sizeof(int) * (length));\
    srand(time(NULL));\
    for (int i = 0; i < (length); i++) {\
        *(array + i) = rand() % (maxRandValue + 1);\
    }\
}
#endif // ARRAY_H_INCLUDED
