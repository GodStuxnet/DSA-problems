#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int comps, max_sz;
} Ans;

int parent_node[100005], size[100005];

int find_set(int v) {
    if (v == parent_node[v]) return v;
    return parent_node[v] = find_set(parent_node[v]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
        size[i] = 1;
    }

    Ans* res = (Ans*)malloc(m * sizeof(Ans));
    int comps = n, max_sz = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int root_a = find_set(a);
        int root_b = find_set(b);

        if (root_a != root_b) {
            if (size[root_a] < size[root_b]) {
                int temp = root_a; root_a = root_b; root_b = temp;
            }
            parent_node[root_b] = root_a;
            size[root_a] += size[root_b];
            comps--;
            if (size[root_a] > max_sz) max_sz = size[root_a];
        }

        res[i].comps = comps;
        res[i].max_sz = max_sz;
    }

    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", res[i].comps, res[i].max_sz);
    }

    free(res);
    return 0;
}

