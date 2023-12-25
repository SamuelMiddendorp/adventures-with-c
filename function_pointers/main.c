#include <stdio.h>

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


    return 0;
}