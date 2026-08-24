#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    int b[a];

    for(int i = 0; i < a; i++){
        scanf("%d",&b[i]);
    }

    for(int i = 0; i < a; i++){
        for(int j = i+1; j < a; j++){
            if(b[i] > b[j]){
                int temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }

    for(int i = 0; i < a; i++){
        if((i+1)%2 == 0){
            if(b[i] > b[i-1]){
                int temp = b[i];
                b[i] = b[i-1];
                b[i-1] = temp;
            }
        }
    }

    for(int i = 0; i < a; i++){
        printf("%d ",b[i]);
    }

    return 0;
}