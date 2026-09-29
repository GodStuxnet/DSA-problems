#include <stdio.h>
#include <stdlib.h>

int parent_node[300005], dist_xor[300005];

int find_set(int v) {
    if (v == parent_node[v]) return v;
    int p = parent_node[v];
    parent_node[v] = find_set(parent_node[v]);
    dist_xor[v] ^= dist_xor[p];
    return parent_node[v];
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) parent_node[i] = i;

    int* ans = (int*)malloc(q * sizeof(int));

    for (int i = 0; i < q; i++) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);

        int root_u = find_set(u);
        int root_v = find_set(v);

        if (root_u != root_v) {
            parent_node[root_u] = root_v;
            dist_xor[root_u] = dist_xor[u] ^ dist_xor[v] ^ x;
            ans[i] = 1;
        } else {
            if ((dist_xor[u] ^ dist_xor[v] ^ x) == 1) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i]) printf("YES\n");
        else printf("NO\n");
    }

    free(ans);
    return 0;
}

