#include <stdio.h>

void foo(char* bar){
    printf(bar);
}

int main(){
    printf("function pointers");
    void (*fun)() = foo;
    fun("bar");
    return 0;
}