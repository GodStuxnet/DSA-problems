#include <stdio.h>
#define max 100
int front = -1;
int rear = -1;

/*
void sort(int stack[],int a){
    int first = -1,second = -1,third = -1;
    for(int i = 0; i < a+1; i++){
        for(int j = i; j < a+1; j++){
             if(stack[i] < stack[j]){
                  int temp = stack[i];
                  stack[i] = stack[j];
                  stack[j] = temp;
             }
        }
    }
    if(a >= 2){
        first = stack[0];
        second = stack[1];
        third = stack[2];
    }

    printf("%d\n",first*second*third);
}

*/
int pop(int stack[]){
    int element;
    if(front == -1 || rear == -1){
         return -1;
    }
    else if(front == rear){
        element = stack[front];
        front = -1;
        rear = -1;
        return element;
    }
    else{
        element = stack[front];
        front++;
        return element;
    }
}
void push(int *stack,int a,int x){
    int first = -1,second = -1,third = -1;
    if(front == -1 || rear == -1){
        front++;
        rear++;
        stack[rear] = x;
    }
    else if(rear == a-1){
        return;
    }
    else{
        if(x < stack[rear]){
            int poped = pop(stack);
            stack[rear] = x;
            stack[++rear] = poped;
        }
        else{
            stack[rear++] = x;
        }
    }

    if(a >= 2){
         first = stack[2];
         second = stack[1];
         third = stack[0];
    }

    printf("%d\n",first*second*third);
}

int main(){
    int a;
    scanf("%d",&a);
    int stack[a];

    for(int i = 0; i < a; i++){
        int x;
        scanf("%d",&x);
        push(stack,i,x);

    }

}