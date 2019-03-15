#include "../Array.h"

int TaskFive() {
    const int length = 5;
    int user_input;
    int id = -1;
    int *array = calloc(length, sizeof(int));
    INITIALIZE_DYNAMIC_ARRAY(length, array, 100);
    SHOW_ARRAY(5, array);
    printf("Print what you want to find\n");
    scanf("%d", &user_input);
    for (int i = 0; i < length; i++) {
        if (*(array + i) == user_input){
            id = i;
        }
    }
    if (id < 0) {
        printf("Error. This value is absent in array");
        return -1;
    }
    else {
        printf("Number %d on index: %d", user_input, id);
    }
    free(array);
    return 0;
}
