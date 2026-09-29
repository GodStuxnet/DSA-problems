#include <stdio.h>

#define MAXN 1001
#define MAXQ 200005

int sum[MAXN][MAXN];
int qy1[MAXQ], qx1[MAXQ], qy2[MAXQ], qx2[MAXQ], ans[MAXQ];
char row[MAXN + 5];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", row);
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (row[j-1] == '*');
    }
    for (int i = 0; i < q; i++)
        scanf("%d %d %d %d", &qy1[i], &qx1[i], &qy2[i], &qx2[i]);
    for (int i = 0; i < q; i++)
        ans[i] = sum[qy2[i]][qx2[i]] - sum[qy1[i]-1][qx2[i]]
               - sum[qy2[i]][qx1[i]-1] + sum[qy1[i]-1][qx1[i]-1];
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}

