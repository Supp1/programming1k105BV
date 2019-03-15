#include "../Array.h"

int TaskEight() {
    const int columns = 4;
    const int lines = 8;
    srand(time(NULL));
    double **array = calloc(lines, sizeof(double*));
    for (int i = 0; i < lines; ++i) {
        *(array + i) = calloc(columns, sizeof(double));
        for (int j = 0; j < columns; ++j) {
            *(*(array + i) + j) = (double)rand()/RAND_MAX * 10.0 - 5.0;
        }
    }
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++){
            printf ("%.3f  ", array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < lines; i++) {
        free(*(array + i));
    }
    free(array);
    return 0;
}
