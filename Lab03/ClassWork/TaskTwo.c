#include "../Array.h"

int TaskTwo(){
    int value = 0;
    int count = 0;
    const int length = 5;
    int* array = malloc(sizeof(int) * length);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        *(array + i) = rand() % 26 - 15;
    }
    SHOW_ARRAY(length, array);
    printf("Write negate digit\n");
    if (1 != scanf("%d", &value)){
        printf("Invalid input");
        return -1;
    }
    for (int i = 0; i < length; i++) {
        if (*(array + i) < 0 && *(array + i) > value){
            count++;
        }
    }
    printf("Amount of negate numbers more than %d:  %d\n", value, count);
    free(array);
    return 0;
}
