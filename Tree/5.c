#include <stdio.h>

#define MAXN 200005
#define LOG 18

int sp[LOG][MAXN], lg[MAXN];
int qa[MAXN], qb[MAXN], ans[MAXN];

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &sp[0][i]);
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int a = sp[j-1][i], b = sp[j-1][i + (1 << (j-1))];
            sp[j][i] = a < b ? a : b;
        }
    for (int i = 0; i < q; i++) scanf("%d %d", &qa[i], &qb[i]);
    for (int i = 0; i < q; i++) {
        int a = qa[i], b = qb[i];
        int j = lg[b - a + 1];
        int x = sp[j][a], y = sp[j][b - (1 << j) + 1];
        ans[i] = x < y ? x : y;
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}

