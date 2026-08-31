#include <stdio.h>
#include <string.h>
#define max 100

char stack[max];
int top = -1;
int balance = 1;

void push(char a){
    stack[++top] = a;
}

char pop(){
    return stack[top--];
}

void empty(){
    if(top == -1 && balance == 1){
        printf("\nBalanced");
    }
    else{
        printf("\nNot Balanced");
    }
}

int main(){

    char exp[50];
    scanf("%s",&exp);
    int len = strlen(exp);
    
    for(int i = 0; i < len; i++){
            if(exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
                push(exp[i]);
            }
            else{
                if(top == -1){
                    balance = 0;
                }
                else{
                    char poped = pop();
                    if((exp[i] == '}' && poped != '{')||
                        (exp[i] == ')' && poped != '(')||
                        (exp[i] == ']' && poped != '[')){
                            balance = 0;
                    }
                }
            }
    }


    empty();

    /*
    while(1){
        char x;
        scanf("%c",&x);
        if(x != '\n'){
            if(x == '{' || x== '(' || x == '['){
                push(x);
            }
            else{
                    if(top == -1){
                        balance = 0;
                    }
                    char poped = pop();
                    if((x == '{' && poped != '}')||
                       (x == '(' && x != ')')||
                       (x == '[' && poped != ']')){
                          balance = 0;
                    }
                }
            }
        }
        else{
            break;
        }
    }

    empty();
    */

}