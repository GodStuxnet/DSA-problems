#include <stdio.h>

int a[5];
int stack1[3];
int stack2[2];
int top1 = -1;
int top2 = -1;

void push1(int x){
   stack1[++top1] = x;
}

void push2(int x){
    stack2[++top2] = x;
}

void pop1(){
    printf("Popped element from stack1 is: %d\n",stack1[top1--]);
}

void pop2(){
    printf("Popped element from stack2 is: %d\n",stack2[top2--]);
}

int main(){
    for(int i = 0; i < 5; i++){
        scanf("%d",&a[i]);
        if((i+1)%2 == 0){
            push2(a[i]);
        }
        else{
            push1(a[i]);
        }
    }

    printf("\n");
    pop1();
    pop2();
}