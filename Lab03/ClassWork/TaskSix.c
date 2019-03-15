#include "../Array.h"

int TaskSix() {
    int check = 1;
    const int length = 5;
    int *array = calloc(length, sizeof(int));
    INITIALIZE_DYNAMIC_ARRAY(length, array, 10);
    SHOW_ARRAY(length, array);
    while(check){
        check = 0;
        for (int i = 0; i < length - 1; ++i) {
            int temp = 0;
            if (*(array + i) > *(array + i + 1)) {
                check = 1;
                temp = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = temp;
            }
        }
    }
    SHOW_ARRAY(length, array);
    free(array);
    return 0;
}
