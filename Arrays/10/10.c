#include <stdio.h>
#define MAX 100
int main(){
    int num;
    int a[MAX];
    int b[MAX][MAX];

    //Getting the input

    int i,j;
    scanf("%d",&num);
    for(i = 0; i < num;i++){
        scanf("%d",&a[i]);
        for(j = 0; j < a[i]; j++){
              scanf("%d",&b[i][j]);
        }

    }

    //Sorting the array
    //sorting because we want the weight of the animal from low to high.so we can increase the snack and give the snack according to the weight
    for(int i = 0; i < num; i++){
         for(int  j = 0; j < a[i]; j++){
            for(int k = j+1; k < a[i]; k++){
                if(b[i][j] > b[i][k]){
                    int temp = b[i][k];
                    b[i][k] = b[i][j];
                    b[i][j] = temp;
                }
         }
       }
    }

    for(int i = 0; i < num; i++){
         for(int  j = 0; j < a[i]-1; j++){
             printf("%d ",b[i][j]);
         }
         printf("\n");
    }
    
    //for each weight the snack(count) will increase
    //checking the element is same or not with same variable if not same, counting the value and giving the snack to the animal and assinging to same variable. if not same it will add the old count(snack of that animal) value. we are totaling the whole snack given to the all animal
    int same = 0;
    int sum = 0;
    int count = 0;
    printf("\n");
    for(int i = 0; i < num; i++){
        for(int j = 0; j < a[i]; j++){
            if(b[i][j] != same){
                same = b[i][j];
                count += 1;
                sum += count;
            }
            else{
                sum += count;
            }
        }
        printf("%d",sum);
        printf("\n");
        sum = 0;
        count = 0;
        same = 0;
    }

}