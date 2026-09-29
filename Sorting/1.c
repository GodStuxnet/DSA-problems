#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compareDesc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int T;
    scanf("%d", &T);

    int answer[T];

    for (int k = 0; k < T; k++)
    {
        int n;

        scanf("%d", &n);

        int girls[n];
        int boys[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &girls[i]);

        for (int i = 0; i < n; i++)
            scanf("%d", &boys[i]);

        qsort(girls, n, sizeof(int), compareAsc);
        qsort(boys, n, sizeof(int), compareDesc);

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (girls[i] % boys[i] == 0 ||
                boys[i] % girls[i] == 0)
            {
                count++;
            }
        }

        answer[k] = count;
    }

    for (int k = 0; k < T; k++)
    {
        printf("%d\n", answer[k]);
    }

    return 0;
}
