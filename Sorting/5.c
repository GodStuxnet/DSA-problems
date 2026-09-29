#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long left;
    long long right;
} Street;

int compare(const void *a, const void *b)
{
    Street *x = (Street *)a;
    Street *y = (Street *)b;

    if (x->left < y->left)
        return -1;

    if (x->left > y->left)
        return 1;

    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);

    char answer[T][4];

    for (int test = 0; test < T; test++)
    {
        int N;
        long long L;

        scanf("%d %lld", &N, &L);

        Street s[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%lld %lld", &s[i].left, &s[i].right);
        }

        qsort(s, N, sizeof(Street), compare);

        long long start = s[0].left;
        long long end = s[0].right;

        int possible = 0;

        for (int i = 1; i < N; i++)
        {
            if (s[i].left <= end)
            {
                if (s[i].right > end)
                    end = s[i].right;
            }
            else
            {
                if (end - start >= L)
                {
                    possible = 1;
                    break;
                }

                start = s[i].left;
                end = s[i].right;
            }
        }

        if (end - start >= L)
        {
            possible = 1;
        }

        // Store answer
        if (possible)
            sprintf(answer[test], "Yes");
        else
            sprintf(answer[test], "No");
    }

    for (int test = 0; test < T; test++)
    {
        printf("%s\n", answer[test]);
    }

    return 0;
}

