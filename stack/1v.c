#include <stdio.h>
#define max 100

int main(){
    int a;
    int a2,b,c;
    scanf("%d",&a);

    //Initializing array
    int A[a];
    int B[a];
    int output[max];

    //Starting value
    b = a-1;
    a2 = 0;
    c = 0; //array index for assinging the output value to the output array

    //Getting the value
    for(int i = 0; i < a; i++){
       scanf("%d",&A[i]);
       B[i] = A[i];
    }
    
    while(a2 != a && b != -1){ //If any one of the element is false then the whole loop stops : True AND False =  False
        if(A[a2] > B[b]){
            output[c] = 1;
            c++;
            b--; //Removing the b value by reducing the index value
        }
        else if(A[a2] < B[b]){
            output[c] = 2;
            c++;
            a2++; //Removing the A value by increasing the index value
        }
        else if(A[a2] == B[b]){
                output[c] = 0;
                //Removing both A and B values
                c++;
                a2++;
                b--;
        }
    }

    printf("\n");
    for(int i = 0; i < c; i++){
        printf("%d ",output[i]);
    }
}