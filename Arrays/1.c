#include <stdio.h>
#include <string.h>

int main()
{
    int num[13] = {
        1, 4, 5, 9, 10, 40, 50,
        90, 100, 400, 500, 900, 1000
    };

    char sym[13][10] = {
        "B", "BW", "W", "BK", "Z", "ZP", "P",
        "ZB", "B", "BG", "G", "BR", "R"
    };

    int n;
    char answers[100][100];
    int ans = 0;

    while (scanf("%d", &n) == 1)
    {
        int i = 0;
        int j = 12;

        while (n > 0)
        {
            int count = n / num[j];
            n = n % num[j];

            while (count > 0)
            {
                int k = 0;

                while (sym[j][k] != '\0')
                {
                    answers[ans][i] = sym[j][k];
                    i++;
                    k++;
                }

                count--;
            }

            j--;
        }

        answers[ans][i] = '\0';

        ans++;
    }

    // Print all answers at the end
    for (int i = 0; i < ans; i++)
    {
        printf("%s\n", answers[i]);
    }

    return 0;
}