#include <stdio.h>

int main()
{
    int p, q;

    scanf("%d %d", &p, &q);

    char arr[p][q];

    int top = 0;
    int bottom = p - 1;
    int left = 0;
    int right = q - 1;

    char ch = 'Y';

    while (top <= bottom && right >= left)
    {
        // Top row
        for (int j = left; j <= right; j++)
            arr[top][j] = ch;

        // Right column
        for (int i = top; i <= bottom; i++)
            arr[i][right] = ch;

        // Bottom row
        for (int j = right; j >= left; j--)
            arr[bottom][j] = ch;

        // Left column
        for (int i = bottom; i >= top; i--)
            arr[i][left] = ch;

        top++;
        bottom--;
        left++;
        right--;

        // Change Y -> 0 -> Y -> 0
        if (ch == 'Y')
            ch = '0';
        else
            ch = 'Y';
    }

    // Print matrix
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}