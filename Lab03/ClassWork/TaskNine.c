#include "../Array.h"

int TaskNine() {
    const int length = 5;
    int maxRandValue = 50;
    int max = 0;
    int maxID = 0;
    int min = maxRandValue;
    int minID = 0;
    int *array = calloc(length, sizeof(int));
    INITIALIZE_DYNAMIC_ARRAY(length, array, maxRandValue);
    SHOW_ARRAY(length, array);
    for (int i = 0; i < length; i++) {
        if (max < *(array + i)) {
            max = *(array + i);
            maxID = i;
        }
        if (min > *(array + i)) {
            min = *(array + i);
            minID = i;
        }
    }
    printf("Max: %d. MaxID: %d\n", max, maxID);
    printf("Min: %d. MinID: %d\n", min, minID);
    free(array);
    return 0;
}
