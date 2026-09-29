#include <stdio.h>

#define NEG -1000000000

int main()
{
    int T;
    scanf("%d", &T);

    int answer[T];

    for (int test = 0; test < T; test++)
    {
        int N, K, P;

        scanf("%d %d %d", &N, &K, &P);

        int dp[P + 1];

        for (int i = 0; i <= P; i++)
            dp[i] = NEG;

        dp[0] = 0;

        for (int stack = 0; stack < N; stack++)
        {
            int prefix[K + 1];

            prefix[0] = 0;

            for (int i = 1; i <= K; i++)
            {
                int x;
                scanf("%d", &x);

                prefix[i] = prefix[i - 1] + x;
            }

            int newdp[P + 1];

            for (int i = 0; i <= P; i++)
                newdp[i] = NEG;

            for (int used = 0; used <= P; used++)
            {
                if (dp[used] == NEG)
                    continue;

                for (int take = 0; take <= K; take++)
                {
                    if (used + take <= P)
                    {
                        int value = dp[used] + prefix[take];

                        if (value > newdp[used + take])
                            newdp[used + take] = value;
                    }
                }
            }

            for (int i = 0; i <= P; i++)
                dp[i] = newdp[i];
        }

        answer[test] = dp[P];
    }

    for (int test = 0; test < T; test++)
    {
        printf("%d\n", answer[test]);
    }

    return 0;
}

