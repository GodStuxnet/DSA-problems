#include <stdio.h>

int digit(int num){
    int sum = 0;
    while(num > 0){
        sum += num%10;
        num = num/10;
    }

    return sum;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    int arr2[a];
    int arr[a];

    for(int i = 0; i < a; i++){
        scanf("%d",&arr2[i]);
        int sum = digit(arr2[i]);
        arr[i] = sum;
    }

    int output[b];
    for(int j = 0; j < b; j++){
        int y;
        scanf("%d",&y);

        output[j] = -1;
        for(int i = y; i < a; i++){
            y = y-1; //because it is in +1 index
            //i should be all the elements after the y (so i left because it is already +1 index)
            if(arr[y] > arr[i]){
              if(arr2[y] < arr2[i]){
                output[j] = i+1;
                break;
              }
            }
        }
   }

   for(int i = 0; i < b; i++){
        printf("%d ",output[i]);
   }

}