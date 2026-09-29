#include <stdio.h>
#include <stdlib.h>

int ascending(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int descending(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int T;
    scanf("%d", &T);

    long long answer[T];

    for (int test = 0; test < T; test++)
    {
        int N;
        scanf("%d", &N);

        int A[N];
        int B[N];

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        for (int i = 0; i < N; i++)
            scanf("%d", &B[i]);

        qsort(A, N, sizeof(int), ascending);
        qsort(B, N, sizeof(int), descending);

        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum += (long long)A[i] * B[i];
        }

        answer[test] = sum;
    }

    for (int test = 0; test < T; test++)
    {
        printf("%lld\n", answer[test]);
    }

    return 0;
}

