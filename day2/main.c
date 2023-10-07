#include <stdio.h>

int main(){
    char chars[100] = {0};

    for(int i = 0; i < 100; i++){
        chars[i] = 'a';
        printf("character: %c \n", chars[i]);
        printf("adress: %p \n", &chars[i]);
    }
    return 0;
}