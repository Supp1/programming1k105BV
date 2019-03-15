#include <math.h>
#include "../Array.h"

int TaskSeven() {
    const int length = 12;
    int* array = calloc(length, sizeof(int));
    int check = 1;
    int check_val = 1;
    INITIALIZE_DYNAMIC_ARRAY(length, array, 40);
    //Bubble sort
    while(check){
        check = 0;
        for (int i = 0; i < length - 1; ++i) {
            if (*(array + i) > *(array + 1 + i)){
                int temp = *(array + i);
                *(array + i) = *(array + i + 1);
                *(array + i + 1) = temp;
                check = 1;
            }
        }
    }
    SHOW_ARRAY(length,array);
    unsigned int user_input = 0;
    printf("Write digit to find: ");
    if (1 != scanf("%d", &user_input)){
        printf("Invalid input");
        return -1;
    }
    int count = 0;
    int left = 0;
    int right = length;
    //Dividing array in half
    while(1){
        int middle = ceil((float)(right + left) / 2);
        if ((right - 1) == left && user_input != array[length - 1]){
            printf("This value is absent");
            break;
        }
        if (user_input > array[middle - 1]) {
            left = middle;
            ++count;
        }
        else if (user_input < array[middle - 1]) {
            right = middle;
            ++count;
        }
        else if (user_input == array[middle - 1]) {
            printf("This number under %d ID", middle-1);
            break;
        }
        if(count >= 30){
            printf("Some errors in code. Please, inform developer about bug");
            return -1;
        }
    }
    free(array);
    return 0;
}
