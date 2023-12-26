#include <stdio.h>
#include "eventDispatcher.h"

struct Foo{
    int (*calcBar)(int);
    int (*calcBas)(int);
};

int calculateBar(int foo){
    return foo + 1;
}

int calculateBas(int foo){
    return foo + 2;
}

void sample(int bar){
    printf("got event! %i", bar);
}

int main(){
    int (*fun)(int foo) = calculateBar;
    printf("%i \n", fun(2));

    fun = calculateBas;
    printf("%i \n", fun(2));

    struct Foo f = {
        calculateBar,
        calculateBas
    };

    printf("%i \n", f.calcBar(2));
    printf("%i \n", f.calcBas(2));

    register_event(sample, 20);
    fire_events();
    return 0;
}