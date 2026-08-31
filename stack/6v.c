#include <stdio.h>

void printArray(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void calculateSpan(int price[],int n,int S[]){
    for(int i = 0 ; i < n; i++){
        int count = 1;
        for(int j = i; j >= 0; j--){
             if(price[j] < price[i]){
                count += 1;
             }
        }
        S[i] = count;
    }

    printArray(S,n);

}

int main(){

    int a;
    scanf("%d",&a);
    int arr[a];
    int s[a];

    for(int i = 0; i < a; i++){
        scanf("%d",&arr[i]);
    }

    calculateSpan(arr,a,s);
    return 0;
}