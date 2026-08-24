#include <stdio.h>
#define max 100

int main(){
    int a,item;
    scanf("%d %d",&a,&item);

    int product[item][max];
    int amount[item];
    for(int i = 0; i < item; i++){
        scanf("%s",&product[i]);
        scanf("%d",&amount[i]);
    }

    printf("\n");
    int total = 0;
    int count = 0;
    for(int i = 0; i < item; i++){
         total += amount[i];
         if(total <= a){
             printf("I can afford %s\n",product[i]);
             count += 1;
         }
         else{
            total -= amount[i];
             printf("I can't afford %s\n",product[i]);
         }
    }

    if(count > 0 && count <= item){
        printf("%d",a - total);
    }
    else{
        printf("I need more Dollar!");
    }
}