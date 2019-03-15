#include <math.h>
#include "../Array.h"

int LabSecond() {
    const int lines = 5, columns = 5;
    int negate = 0, pos = 0, null = 0;
    srand(time(NULL));
    double **array = calloc(lines, sizeof(double*));
    for(int i = 0; i < lines; ++i) {
        *(array + i) = calloc(columns, sizeof(double));
        for(int j = 0; j < columns; ++j) {
            array[i][j] = rand() % 10;
        }
    }
    //SHOW ARRAY
    for(int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%.2f ", array[i][j]);
            printf("j%d  ",j);
        }
        printf("i %d",i);
        printf("\n");
    }
    //REPLACING ELEMENTS
    for (int i = 0; i < lines; ++i) {
        for(int j = 0; j < columns; ++j) {
            array[i][j] = array[i][j] * acos((double)(i + 1)/(i + j + 2));
        }
    }
    printf("NEW ARRAY:\n");
    for(int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%.3f  ", array[i][j]);
        }
        printf("\n");
    }
    for(int j = 0; j < columns; ++j)
    {
        for(int i = 0; i < lines; ++i)
        {
            array[i][j] != 0 ?(array[i][j] < 0? negate++ : pos++): null++;
        }
        printf("Column %d:\n\t%d Negate numbers \t%d Positive numbers\t%d Null\n",j ,negate, pos, null);
        negate = 0; pos = 0; null = 0;
    }
    for(int i = 0; i < lines; ++i) {
        free(*(array + i));
    }
    free(array);
    return 0;
}
