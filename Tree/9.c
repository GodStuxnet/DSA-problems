#include <stdio.h>
#include <stdlib.h>

int *pa, *pb;
int find(int *p, int x) {
    while (p[x] != x) { p[x] = p[p[x]]; x = p[x]; }
    return x;
}
int unite(int *p, int a, int b) {
    a = find(p, a); b = find(p, b);
    if (a == b) return 0;
    p[a] = b;
    return 1;
}

int main() {
    int n, m1, m2;
    scanf("%d %d %d", &n, &m1, &m2);
    pa = malloc((n + 1) * sizeof(int));
    pb = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) pa[i] = pb[i] = i;

    for (int i = 0; i < m1; i++) { int u, v; scanf("%d %d", &u, &v); unite(pa, u, v); }
    for (int i = 0; i < m2; i++) { int u, v; scanf("%d %d", &u, &v); unite(pb, u, v); }

    int *ru = malloc(n * sizeof(int));
    int *rv = malloc(n * sizeof(int));
    int rc = 0;

    for (int i = 2; i <= n; i++) {
        if (find(pa, 1) != find(pa, i) && find(pb, 1) != find(pb, i)) {
            unite(pa, 1, i);
            unite(pb, 1, i);
            ru[rc] = 1; rv[rc] = i; rc++;
        }
    }

    int *P = malloc(n * sizeof(int)), *Q = malloc(n * sizeof(int));
    int pc = 0, qc = 0;
    for (int i = 2; i <= n; i++) {
        if (find(pa, i) != find(pa, 1)) P[pc++] = i;
        if (find(pb, i) != find(pb, 1)) Q[qc++] = i;
    }

    int i = 0, j = 0;
    while (i < pc && j < qc) {
        if (find(pa, P[i]) == find(pa, 1)) i++;
        else if (find(pb, Q[j]) == find(pb, 1)) j++;
        else {
            unite(pa, P[i], Q[j]);
            unite(pb, P[i], Q[j]);
            ru[rc] = P[i]; rv[rc] = Q[j]; rc++;
            i++; j++;
        }
    }

    printf("%d\n", rc);
    for (int k = 0; k < rc; k++) printf("%d %d\n", ru[k], rv[k]);
    return 0;
}

