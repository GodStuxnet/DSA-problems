#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    int answer[T];

    for (int test = 0; test < T; test++)
    {
        int N, K;

        scanf("%d %d", &N, &K);

        int maxDistance = 0;

        for (int i = 0; i < N; i++)
        {
            int x;
            scanf("%d", &x);

            if (x > maxDistance)
                maxDistance = x;
        }

        if (maxDistance > K)
            answer[test] = maxDistance - K;
        else
            answer[test] = -1;
    }

    for (int test = 0; test < T; test++)
    {
        printf("%d\n", answer[test]);
    }

    return 0;
}
