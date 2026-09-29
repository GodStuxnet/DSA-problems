#include <stdio.h>
#include <stdlib.h>

int N;
int *bit;

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}
void upd(int i, int v) { for (; i <= N; i += i & -i) bit[i] += v; }
int qry(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }

long long *vals;
int id(long long x) {         
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (vals[mid] < x) lo = mid + 1; else hi = mid;
    }
    return lo + 1;
}

int upper(long long x) {
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (vals[mid] <= x) lo = mid + 1; else hi = mid;
    }
    return lo;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    long long *p = malloc((n + 1) * sizeof(long long));
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);

    char *type = malloc(q);
    long long *A = malloc(q * sizeof(long long));
    long long *B = malloc(q * sizeof(long long));
    vals = malloc((n + 2 * q) * sizeof(long long));
    int cnt = 0;
    for (int i = 1; i <= n; i++) vals[cnt++] = p[i];
    for (int i = 0; i < q; i++) {
        char c;
        scanf(" %c %lld %lld", &c, &A[i], &B[i]);
        type[i] = c;
        if (c == '!') vals[cnt++] = B[i];
        else { vals[cnt++] = A[i]; vals[cnt++] = B[i]; }
    }
    qsort(vals, cnt, sizeof(long long), cmp);
    int m = 0;
    for (int i = 0; i < cnt; i++)
        if (i == 0 || vals[i] != vals[i - 1]) vals[m++] = vals[i];
    N = m;
    bit = calloc(N + 2, sizeof(int));

    for (int i = 1; i <= n; i++) upd(id(p[i]), 1);

    int *out = malloc(q * sizeof(int));
    int oc = 0;
    for (int i = 0; i < q; i++) {
        if (type[i] == '!') {
            int k = (int)A[i];
            upd(id(p[k]), -1);
            p[k] = B[i];
            upd(id(p[k]), 1);
        } else {
            int r = qry(upper(B[i]));
            int l = qry(upper(A[i] - 1));
            out[oc++] = r - l;
        }
    }
    for (int i = 0; i < oc; i++) printf("%d\n", out[i]);
    return 0;
}

