#include "../Array.h"

int TaskOne() {
    const int length = 5;
    int* array = calloc(length, sizeof(int));
    srand(time(NULL));
    int i = 0;
    while(i < length){
        int value = rand() % 3001 - 1000;
        printf("Value:      %d\n", value);
        if(value >= 100 && value <= 200) {
            array[i] = value;
            ++i;
        }
    }
    printf("\nARRAY:\n");
    SHOW_ARRAY(length, array);
    free(array);
    return 0;
}
