#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct mystack{
    struct node *top;
};

void push(struct mystack *ms,int a){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = ms->top;
    ms->top = newNode;
}

int pop(struct mystack *ms){
    if(ms->top == NULL){
        return -1;
    }
    struct node *temp = ms->top;
    int popdata = temp->data;
    ms->top = ms->top->next;
    free(temp);
    return popdata;
}

void merge(struct mystack *ms1,struct mystack *ms2){
    if(ms1->top == NULL){
        ms1->top = ms2->top;
        return;
    }
    struct node *temp = ms1->top;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ms2->top;
}

int main(){
   int a,b;
   scanf("%d %d",&a,&b);

   struct mystack ms1;
   ms1.top = NULL;

   struct mystack ms2;
   ms2.top = NULL;

   for(int i = 0; i < a; i++){
       int x;
       scanf("%d",&x);
       push(&ms1,x);
   }
   
   for(int i = 0; i < b; i++){
       int x;
       scanf("%d",&x);
       push(&ms2,x);
   }

   merge(&ms1,&ms2);

   struct node *temp = ms1.top;
   while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
   }
}