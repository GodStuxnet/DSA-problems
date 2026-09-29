#include <stdio.h>

#define MAX 205

int A[MAX][MAX];
int rightEnd[MAX][MAX];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int R, C, L;

        scanf("%d %d %d", &R, &C, &L);

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }

        for (int row = 0; row < R; row++)
        {
            int maxDeque[MAX];
            int minDeque[MAX];

            int maxFront = 0, maxBack = 0;
            int minFront = 0, minBack = 0;

            int right = 0;

            for (int left = 0; left < C; left++)
            {
                while (right < C)
                {
                    int x = A[row][right];

                    if (right > left)
                    {
                        int currentMax = A[row][maxDeque[maxFront]];
                        int currentMin = A[row][minDeque[minFront]];

                        int newMax = currentMax;
                        int newMin = currentMin;

                        if (x > newMax)
                            newMax = x;

                        if (x < newMin)
                            newMin = x;

                        if (newMax - newMin > L)
                            break;
                    }

                    while (maxBack > maxFront &&
                           A[row][maxDeque[maxBack - 1]] <= x)
                    {
                        maxBack--;
                    }

                    maxDeque[maxBack++] = right;

                    while (minBack > minFront &&
                           A[row][minDeque[minBack - 1]] >= x)
                    {
                        minBack--;
                    }

                    minDeque[minBack++] = right;

                    right++;
                }

                rightEnd[row][left] = right - 1;

                if (maxFront < maxBack &&
                    maxDeque[maxFront] == left)
                {
                    maxFront++;
                }

                if (minFront < minBack &&
                    minDeque[minFront] == left)
                {
                    minFront++;
                }
            }
        }

        int answer = 0;

        for (int top = 0; top < R; top++)
        {
            int commonRight[MAX];

            for (int j = 0; j < C; j++)
                commonRight[j] = C - 1;

            for (int bottom = top; bottom < R; bottom++)
            {
                for (int left = 0; left < C; left++)
                {
                    if (rightEnd[bottom][left] < commonRight[left])
                        commonRight[left] = rightEnd[bottom][left];

                    int width = commonRight[left] - left + 1;
                    int height = bottom - top + 1;

                    int area = width * height;

                    if (area > answer)
                        answer = area;
                }
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
