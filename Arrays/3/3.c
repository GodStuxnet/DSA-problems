#include <stdio.h>
#define max 100

int main(){
    int d;
    int a[max];
    int b[max][max];
    int value[max];
    int k = 0;

    scanf("%d",&d);
    for(int i = 0; i < d; i++){
        scanf("%d",&a[i]);
        for(int j = 0; j < a[i]; j++){
            scanf("%d",&b[i][j]);
            //Runtime checking
            if(j != 0){ //checks if the index is more than first index to check the back element through index
                if(b[i][j] > b[i][j-1]){ //second element > first element (it means increasing)
                    value[k] = j-1; //first element
                    value[k+1] = j; //second element
                    k+=2; //increasing for each addition of two element in a array
                }
            }
        }
    }

    printf("\n");
    for(int i = 0; i < k; i++){
        if((i+1)%2 == 0){ //it prints two element for each iteration
            printf("%d %d\n",value[i-1],value[i]);
        }
    }

}