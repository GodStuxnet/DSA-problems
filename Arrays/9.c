#include <stdio.h>

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    int arr[r][c];
    int arrTemp[r][c];

    // Input
    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            scanf("%d", &arr[m][n]);
            arrTemp[m][n] = arr[m][n];
        }
    }

    // Find 1's and make corresponding row and column 1
    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            if (arr[m][n] == 1)
            {
                // Make row m = 1
                for (int j = 0; j < c; j++)
                    arrTemp[m][j] = 1;

                // Make column n = 1
                for (int i = 0; i < r; i++)
                    arrTemp[i][n] = 1;
            }
        }
    }

    // Output
    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            printf("%d ", arrTemp[m][n]);
        }
        printf("\n");
    }

    return 0;
}