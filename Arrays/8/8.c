#include <stdio.h>

int main(){
    int P,Q;
    scanf("%d %d",&P,&Q);
    int mat[P][Q];

    for(int m = 0;m < P; m++){
        for(int n = 0; n < Q; n++){
            scanf("%d",&mat[m][n]);
        }

    }

    for(int m = 0; m < P; m++){
        for(int n = 0; n < Q; n++){\
           if(mat[m][n] == 1){
               for(int i = 0; i < m; i++){
                    mat[i][n] = 1;
               }
               for(int j = 0; j < n; j++){
                    mat[m][j] = 1;
               }
            }
        }
    }


    printf("\n");
    for(int i = 0; i < P;i++){
        for(int j = 0; j < Q; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

}