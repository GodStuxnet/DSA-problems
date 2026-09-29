#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    char answer[T][4];

    for (int test = 0; test < T; test++)
    {
        int n;

        scanf("%d", &n);

        int side1 = 0;
        int side2 = 0;

        for (int i = 0; i < n; i++)
        {
            int x, y, h;

            scanf("%d %d %d", &x, &y, &h);

            if (x > y)
                side1++;
            else if (x < y)
                side2++;
        }

        if (side1 == side2)
            sprintf(answer[test], "YES");
        else
            sprintf(answer[test], "NO");
    }

    for (int test = 0; test < T; test++)
    {
        printf("%s\n", answer[test]);
    }

    return 0;
}

