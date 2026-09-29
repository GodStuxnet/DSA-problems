#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    long long mask;
} Edge;

int parent[100005];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    long long c[64];
    for (int i = 0; i < k; i++) scanf("%lld", &c[i]);

    Edge* edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        long long mask = 0;
        for (int j = 0; j < l; j++) {
            int token_idx;
            scanf("%d", &token_idx);
            token_idx--;
            mask |= (1LL << token_idx);
        }
        edges[i].u = u;
        edges[i].v = v;
        edges[i].mask = mask;
    }

    long long chosen_mask = 0;
    for (int bit = k - 1; bit >= 0; bit--) {
        for (int i = 1; i <= n; i++) parent[i] = i;

        long long test_mask = chosen_mask | ((1LL << bit) - 1);
        int comps = n;

        for (int i = 0; i < m; i++) {
            if ((edges[i].mask & ~test_mask) == 0) {
                if (find_set(edges[i].u) != find_set(edges[i].v)) {
                    union_sets(edges[i].u, edges[i].v);
                    comps--;
                }
            }
        }

        if (comps > 1) {
            chosen_mask |= (1LL << bit);
        }
    }

    for (int i = 1; i <= n; i++) parent[i] = i;
    int comps = n;
    for (int i = 0; i < m; i++) {
        if ((edges[i].mask & ~chosen_mask) == 0) {
            if (find_set(edges[i].u) != find_set(edges[i].v)) {
                union_sets(edges[i].u, edges[i].v);
                comps--;
            }
        }
    }

    if (comps > 1) {
        printf("-1\n");
    } else {
        long long total_cost = 0;
        for (int i = 0; i < k; i++) {
            if ((chosen_mask >> i) & 1) total_cost += c[i];
        }
        printf("%lld\n", total_cost);
    }

    free(edges);
    return 0;
}

