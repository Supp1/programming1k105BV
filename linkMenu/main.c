#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//MENU WITH LINKS ON FUNCTIONS
typedef void (*fun) (void);

void toUp (void);
void toLow (void);
void findMax(void);

int main()
{
    int user = -1;
    fun actions[3] = {NULL};
    actions[0] = toUp;
    actions[1] = toLow;
    actions[2] = findMax;
    printf("What do you want to do?\n\t[0] Word to Upper case\n\t[1] Word to Lower case\n\t[2] Find the most long word in sentence\n");
    if(1 != scanf("%d", &user)) {
        printf("INVALID INPUT");
        return 1;
    }
    if(actions[user] != NULL) {
        actions[user]();
    }
    return 0;
}

void toUp() {
    char word[30];
    memset(word, 0, 30*sizeof(char));
    printf("Write any word\n");
    fflush(stdin);
    gets(word);
    int i = 0;
    while(word[i++]) {
        word[i-1] = toupper(word[i-1]);
    }
    puts(word);
}

void toLow() {
    char word[30];
    memset(word, 0, 30*sizeof(char));
    printf("Write any word\n");
    fflush(stdin);
    gets(word);
    int i = 0;
    while(word[i++]) {
        word[i-1] = tolower(word[i-1]);
    }
    puts(word);
}

void findMax() {
    char sent[100];
    memset(sent, 0, 100*sizeof(char));
    printf("Write any sentence\n");
    fflush(stdin);
    gets(sent);
    int i = 0;
    int count = 0; int countMax = 0;
    while(sent[i++]) {
        if(isspace(sent[i-1])||ispunct(sent[i-1])) {
            if(count > countMax) {
                countMax = count;
            }
            count = 0;
        }
        ++count;
    }
    countMax == 0? printf("Something goes wrong. Maybe you write only one word?\n") :
    printf("Max length of word: %d\n", countMax);
}
