#include <stdio.h>

#define SIZE 1
#define ARENA_SIZE 10000

char arena[ARENA_SIZE] = {0};
size_t arena_size = 0;

void* arena_alloc(size_t size){
    void* adress = ((char *)arena) + arena_size;
    arena_size += size;
    return adress;
}
void arena_func(){
    printf("Memory arena");
    char* addr = arena_alloc(32);
    for(int i = 0; i < 32; i++){
        addr[i] = i + '0';
        printf("value: %c \n", addr[i]);
    }
}

int main(){
    char chars[SIZE] = {0};

    for(int i = 0; i < SIZE; i++){
        chars[i] = 'a';
        printf("character: %c \n", chars[i]);
        printf("adress: %p \n", &chars[i]);
    }
    arena_func();
    return 0;
}
