#include "../Array.h"

int TaskTen() {
    const int lines = 16, columns = 8;
    srand(time(NULL));
    int **array = calloc(lines, sizeof(int*));
    for (int i = 0; i < lines; ++i) {//Initialization
        *(array + i) = calloc(columns, sizeof(int));
        for (int j = 0; j < columns; ++j) {
            array[i][j] = 0;
        }
    }
    //Face Borders
    for (int i = 2; i < lines - 2; ++i){
        array[i][0] = 1;
        array[i][columns - 1] = 1;
    }
    for (int j = 2; j < columns - 2; ++j) {
        array[0][j] = 1;
        array[lines - 1][j] = 1;
    }
    array[1][1] = 1;
    array[lines - 2][1] = 1;
    array[1][columns - 2] = 1;
    array[lines - 2][columns - 2] = 1;
    //Eyes
    for (int i = 3; i < (lines / 2); ++i){
        array[i][columns / 2 + 1] = 1;
        array[i][columns / 2 - 2] = 1;
    }
    //Smile
    for (int j = 2; j < columns - 2; ++j) {
        array[lines - 4][j] = 1;
    }
    array[lines - 5][1] = 1;
    array[lines - 5][columns - 2] = 1;
    //Show Array
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d  ", array[i][j]);
        }
        printf("\n");
    }
    //Free Array
    for (int i = 0; i < lines; ++i) {
        free(*(array + i));
    }
    free(array);
    return 0;
}
