#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        long long W, H;
        scanf("%lld %lld", &W, &H);

        long long L, S;

        if (W > H)
        {
            L = W;
            S = H;
        }
        else
        {
            L = H;
            S = W;
        }

        if (8 * S <= 5 * L && 10 * L <= 17 * S)
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
