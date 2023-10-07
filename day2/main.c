#include <stdio.h>

#define SIZE 1

void arena(){
    printf("Memory arena");
}

int main(){
    char chars[SIZE] = {0};

    for(int i = 0; i < SIZE; i++){
        chars[i] = 'a';
        printf("character: %c \n", chars[i]);
        printf("adress: %p \n", &chars[i]);
    }
    arena();
    return 0;
}
