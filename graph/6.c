#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[505][505], match_girl[505], visited[505];

int dfs(int u, int m) {
    for (int v = 1; v <= m; v++) {
        if (adj[u][v] && !visited[v]) {
            visited[v] = 1;
            if (match_girl[v] < 0 || dfs(match_girl[v], m)) {
                match_girl[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, k;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
    }

    memset(match_girl, -1, sizeof(match_girl));
    int total_pairs = 0;

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i, m)) total_pairs++;
    }

    printf("%d\n", total_pairs);
    for (int v = 1; v <= m; v++) {
        if (match_girl[v] != -1) {
            printf("%d %d\n", match_girl[v], v);
        }
    }

    return 0;
}

