#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char variable;
    char value[50];

    double M = 0, D = 0, X = 0;
    int unknown = 0;

    for (int i = 0; i < 3; i++)
    {
        scanf(" %c %s", &variable, value);

        if (value[0] == '?')
        {
            unknown = variable;
        }
        else
        {
            double num = atof(value);

            if (variable == 'M')
                M = num;
            else if (variable == 'D')
                D = num;
            else if (variable == 'X')
                X = num;
        }
    }

    double answer;

    if (unknown == 'M')
    {
        answer = -D * X;
        printf("m %.2f\n", answer);
    }
    else if (unknown == 'D')
    {
        answer = -M / X;
        printf("d %.2f\n", answer);
    }
    else
    {
        answer = -M / D;

        /* Avoid printing -0.00 */
        if (fabs(answer) < 0.0005)
            answer = 0;

        printf("x %.2f\n", answer);
    }

    return 0;
}

