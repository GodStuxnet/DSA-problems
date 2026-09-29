#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    int answer[T];

    for (int k = 0; k < T; k++)
    {
        int M;
        char s[101];

        scanf("%d", &M);
        scanf("%s", s);

        int len = (M + 1) / 2;
        int maxSum = 0;

        for (int i = 0; i <= M - len; i++)
        {
            int sum = 0;

            for (int j = i; j < i + len; j++)
            {
                sum += s[j] - '0';
            }

            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }

        answer[k] = maxSum;
    }


    printf("\n");
    for (int k = 0; k < T; k++)
    {
        printf("%d\n", answer[k]);
    }

    return 0;
}