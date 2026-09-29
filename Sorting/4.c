#include <stdio.h>
#include <stdlib.h>

int compareDesc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int T;
    scanf("%d", &T);

    int answer[T];

    for (int test = 0; test < T; test++)
    {
        int n, m;

        scanf("%d %d", &n, &m);

        int a[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        qsort(a, n, sizeof(int), compareDesc);

        int sum = 0;
        int count = 0;

        for (int i = 0; i < n && count < m; i++)
        {
            if (a[i] > 0)
            {
                sum += a[i];
                count++;
            }
        }

        answer[test] = sum;
    }

    for (int test = 0; test < T; test++)
    {
        printf("%d\n", answer[test]);
    }

    return 0;
}
