#include <math.h>
#include "../Array.h"

int TaskThree() {
    const int length = 5;
    unsigned int result = 0;
    int *array = calloc(length, sizeof(int));
    INITIALIZE_DYNAMIC_ARRAY(length, array, 10);
    SHOW_ARRAY(length, array);
    for (int i = 0; i < length; i++) {
        result += pow(2, *(array + i));
    }
    printf("L-norm is: %d\n", result);
    free(array);
    return 0;
}
