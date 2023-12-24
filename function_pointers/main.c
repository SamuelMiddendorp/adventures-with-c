#include <stdio.h>

int calculateBar(int foo){
    return foo + 1;
}

int calculateBas(int foo){
    return foo + 2;
}

int main(){
    int (*fun)(int foo) = calculateBar;
    printf("%i \n", fun(2));

    fun = calculateBas;
    printf("%i \n", fun(2));

    return 0;
}