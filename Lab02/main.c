#include "main.h"

int main()
{
    char user_key = 'a';
    printf("Press Key\n\t[1]  View Task One\n\t[2]  View Task Two\n\t[3]  View Task Three\n\t[6]  View Task Six\n\t[7]  View Task Seven\n\t[F/f] View Task Ten\n\t[L/l]  View Lab Work\n\t[Q/q]  Exit\n\t[H/h]  Help\n\n");
    scanf("%c", &user_key);
    switch (user_key)
    {
    case '1':
        getchar();
        return TaskOne();
    case '2':
        getchar();
        return TaskTwo();
    case '3':
        getchar();
        return TaskThree();
    case '4':
        getchar();
        return TaskFour();
    case '5':
        break;
    case '6':
        getchar();
        return TaskSix();
    case '7':
        getchar();
        return TaskSeven();
    case'F':
        case'f':
                getchar();
        return TaskTen();
    case'L':
    case 'l':
        getchar();
        printf("Choose part you want to see:");
        printf("\n\t[1] View Part 1");
        printf("\n\t[2] View Part 2\n");
        scanf("%c", &user_key);
        switch (user_key)
        {
        case '1':
            getchar();
            return LabPart1();
        case '2':
            getchar();
            return LabPart2();
        }
    case 'q':
    case 'Q':
        getchar();
        return 0;
    case 'H':
    case 'h':
        printf("It's Menu for Auditor Work 2 by Victor Bayev\n");
        break;
    }
    return 0;
}
