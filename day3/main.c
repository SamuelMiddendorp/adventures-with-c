#include <stdio.h>
#include <stdlib.h>

struct node{
    char value;
    struct node* next;
};

struct linkedList{
    struct node* head;
};


void add(struct linkedList* l, char c){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->value = c;
    new->next = l->head;    
    l->head = new;
}
void print(struct linkedList* l){
    struct node* current = l->head;
    while(current != NULL){
        printf("Value: %c \n", current->value);
        current = current->next;
    }
}

int main(void){
    printf("day3 \n");
    struct linkedList* l = malloc(sizeof(struct linkedList));
    l->head = NULL;
    add(l, 'A');
    add(l, 'C');
    add(l, 'A');
    add(l, 'A');

    print(l);
}

