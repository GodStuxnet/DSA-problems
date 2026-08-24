#include <stdio.h>

int main(){
    int T;
    int row,col;
    scanf("%d",&T);
    scanf("%d %d",&row,&col);
    int C[row][col];
    int values[T];

    for(int l = 0 ; l < T; l++){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    scanf("%d",&C[i][j]);
                }
            }

            int X1,X2,Y1,Y2;
            scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);

            int total = C[X1-1][Y1-1] + C[X2-1][Y2-1];
            values[l] = total;
    }

    printf("\n");
    for(int i = 0; i < T; i++){
        printf("%d\n",values[i]);
    }

}