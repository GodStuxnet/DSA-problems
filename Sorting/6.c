#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        if (i == 3)
        {
            for (int k = 0; k < n; k++)
            {
                printf("%d", a[k]);

                if (k != n - 1)
                    printf(" ");
            }

            printf("\n");
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);

        if (i != n - 1)
            printf(" ");
    }

    return 0;
}
