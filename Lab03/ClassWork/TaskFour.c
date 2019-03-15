#include <math.h>
#include "../Array.h"

int TaskFour() {
    const int length = 5;
    int maxRandValue = 50;
    int max = 0;
    int min = maxRandValue;
    int *array = calloc(length, sizeof(int));
    INITIALIZE_DYNAMIC_ARRAY(length, array, maxRandValue);
    SHOW_ARRAY(length, array);
    for (int i = 0; i < length; i++) {
        if (max < *(array + i)) {
            max = *(array + i);
        }
        if (min > *(array + i)) {
            min = *(array + i);
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    free(array);
    return 0;
}
