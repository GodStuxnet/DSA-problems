#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *push(struct node *top,int a){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = top;
    top = newNode;
    return top;
}

struct node *pop(struct node **top){
    *top = (*top)->next;
}

int main(){

    int a,b;
    struct node *stack = NULL;
    scanf("%d %d",&a,&b);

    for(int i = 0; i < a; i++){
        int x;
        scanf("%d",&x);
        stack = push(stack,x);
    }

    for(int j = 0; j < b; j++){
        int x;
        scanf("%d",&x);
        stack = push(stack,x);
    }
    
    while(stack != NULL){
        printf("%d ",stack->data);
        stack = stack->next;
    }
    
}