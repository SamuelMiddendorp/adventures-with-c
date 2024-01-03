#include <stdio.h>
#include <stdlib.h>

#define MAX_SCENES 100

typedef struct{
	void(*run)();
} Scene;

typedef struct{
	Scene** stateStack;
	int current;
} SceneManager;

void run1(){
	printf("BaDaBing \n");
}

void run2(){
	printf("BaDaBoom \n");
}

void initSceneManager(SceneManager* sceneManager){
	sceneManager->stateStack = malloc(MAX_SCENES * sizeof(Scene*));
	sceneManager->current = 0;
}

void pushScene(SceneManager* sceneManager, Scene* scene){
	sceneManager->stateStack[++sceneManager->current] = scene;	
}

void runScene(SceneManager* sceneManager){
	sceneManager->stateStack[sceneManager->current]->run();
}


int main(){
	printf("foobar \n");

	SceneManager sceneManager;
	initSceneManager(&sceneManager);

	Scene s1 = {&run1};
	Scene s2 = {&run2};

	pushScene(&sceneManager, &s1);
	runScene(&sceneManager);

	pushScene(&sceneManager, &s2);
	runScene(&sceneManager);

	pushScene(&sceneManager, &s1);
	runScene(&sceneManager);

	return 0;
}
