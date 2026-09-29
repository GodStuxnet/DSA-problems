#include <stdio.h>
#include <stdlib.h>

int n, K;
int *deg, *par, *dep, *head, *nxt, *to, *ord, *tmp;
int **up, **rk;

int cmp_rank(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    int *r0 = rk[K];
    return r0[x] - r0[y];
}

int cmp_deg(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return rk[0][x] - rk[0][y];
}

int curk;
int cmp_pair(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    int *r = rk[curk];
    int *u = up[curk];
    if (r[x] != r[y]) return r[x] < r[y] ? -1 : 1;
    int rx = r[u[x]], ry = r[u[y]];
    if (rx != ry) return rx < ry ? -1 : 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    deg = calloc(n + 1, sizeof(int));
    par = calloc(n + 1, sizeof(int));
    dep = calloc(n + 1, sizeof(int));
    head = malloc((n + 1) * sizeof(int));
    nxt = malloc(2 * n * sizeof(int));
    to = malloc(2 * n * sizeof(int));
    ord = malloc((n + 1) * sizeof(int));
    tmp = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) head[i] = -1;
    int ec = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++; deg[v]++;
        to[ec] = v; nxt[ec] = head[u]; head[u] = ec++;
        to[ec] = u; nxt[ec] = head[v]; head[v] = ec++;
    }

    int qh = 0, qt = 0;
    ord[qt++] = 1; par[1] = 0; dep[1] = 0;
    while (qh < qt) {
        int u = ord[qh++];
        for (int e = head[u]; e != -1; e = nxt[e])
            if (to[e] != par[u]) { par[to[e]] = u; dep[to[e]] = dep[u] + 1; ord[qt++] = to[e]; }
    }
    K = 1;
    while ((1 << K) <= n) K++;
    up = malloc((K + 1) * sizeof(int *));
    rk = malloc((K + 1) * sizeof(int *));
    for (int k = 0; k <= K; k++) {
        up[k] = calloc(n + 1, sizeof(int));
        rk[k] = calloc(n + 1, sizeof(int));
    }
    for (int v = 1; v <= n; v++) up[0][v] = par[v];
    for (int k = 1; k <= K; k++)
        for (int v = 1; v <= n; v++) up[k][v] = up[k-1][up[k-1][v]];

    for (int i = 0; i < n; i++) ord[i] = i + 1;
    int *dd = deg;
    for (int v = 1; v <= n; v++) rk[0][v] = dd[v];
    curk = -1;
    {
        qsort(ord, n, sizeof(int), cmp_deg);
        int r = 0, prev = -1;
        for (int i = 0; i < n; i++) {
            int v = ord[i];
            if (dd[v] != prev) { r++; prev = dd[v]; }
            tmp[v] = r;
        }
        for (int v = 1; v <= n; v++) rk[0][v] = tmp[v];
    }
    for (int k = 0; k < K; k++) {
        curk = k;
        for (int i = 0; i < n; i++) ord[i] = i + 1;
        qsort(ord, n, sizeof(int), cmp_pair);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || cmp_pair(&ord[i-1], &ord[i]) != 0) r++;
            rk[k+1][ord[i]] = r;
        }
    }
    for (int i = 0; i < n; i++) ord[i] = i + 1;
    qsort(ord, n, sizeof(int), cmp_rank);

    long long total = 0;
    for (int v = 1; v <= n; v++) total += dep[v] + 1;
    long long common = 0;
    for (int i = 1; i < n; i++) {
        int u = ord[i-1], v = ord[i];
        long long l = 0;
        for (int k = K - 1; k >= 0; k--) {
            if (u && v && dep[u] + 1 >= (1 << k) && dep[v] + 1 >= (1 << k) && rk[k][u] == rk[k][v]) {
                l += (1 << k);
                u = up[k][u];
                v = up[k][v];
            }
        }
        common += l;
    }
    printf("%lld\n", total - common);
    return 0;
}

