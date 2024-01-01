#include <stdio.h>

#define MAX_SCENES 100;


typedef struct{
	void(*run)();
} Scene;

typedef struct{
	Scene** stateStack;
	int current;
};


int main(){
	printf("foobar");
	return 0;
}
