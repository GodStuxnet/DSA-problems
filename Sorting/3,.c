#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;

    if (x < y)
        return -1;
    else if (x > y)
        return 1;

    return 0;
}

int main()
{
    int q;
    scanf("%d", &q);

    char answer[q][20];

    for (int test = 0; test < q; test++)
    {
        int n;
        scanf("%d", &n);

        long long row[n];
        long long col[n];

        for (int i = 0; i < n; i++)
        {
            row[i] = 0;
            col[i] = 0;
        }

        // Read matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long x;
                scanf("%lld", &x);

                row[i] += x;
                col[j] += x;
            }
        }

        qsort(row, n, sizeof(long long), compare);
        qsort(col, n, sizeof(long long), compare);

        int possible = 1;

        for (int i = 0; i < n; i++)
        {
            if (row[i] != col[i])
            {
                possible = 0;
                break;
            }
        }

        if (possible)
            sprintf(answer[test], "Possible");
        else
            sprintf(answer[test], "Impossible");
    }

    for (int test = 0; test < q; test++)
    {
        printf("%s\n", answer[test]);
    }

    return 0;
} 

