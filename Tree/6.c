#include <stdio.h>

#define MAXN 200005
#define LOG 18

int up[LOG][MAXN];
int qx[MAXN], qk[MAXN], ans[MAXN];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) scanf("%d", &up[0][i]);
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++)
            up[j][i] = up[j-1][up[j-1][i]];
    for (int i = 0; i < q; i++) scanf("%d %d", &qx[i], &qk[i]);
    for (int i = 0; i < q; i++) {
        int x = qx[i], k = qk[i];
        for (int j = 0; j < LOG && x; j++)
            if (k & (1 << j)) x = up[j][x];
        ans[i] = x ? x : -1;
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}

