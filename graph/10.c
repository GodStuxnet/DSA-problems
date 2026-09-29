#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cap[505][505], flow_net[505][505], parent_node[505];
int orig_u[1005], orig_v[1005];
int vis[505];

int bfs(int s, int t, int n) {
    memset(parent_node, -1, sizeof(parent_node));
    parent_node[s] = s;
    int queue[505], head = 0, tail = 0;
    queue[tail++] = s;

    while (head < tail) {
        int u = queue[head++];
        if (u == t) break;
        for (int v = 1; v <= n; v++) {
            if (parent_node[v] == -1 && cap[u][v] - flow_net[u][v] > 0) {
                parent_node[v] = u;
                queue[tail++] = v;
            }
        }
    }
    return parent_node[t] != -1;
}

void dfs_reach(int u, int n) {
    vis[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && cap[u][v] - flow_net[u][v] > 0) {
            dfs_reach(v, n);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &orig_u[i], &orig_v[i]);
        cap[orig_u[i]][orig_v[i]] += 1;
        cap[orig_v[i]][orig_u[i]] += 1;
    }

    int min_cut = 0;
    while (bfs(1, n, n)) {
        for (int v = n; v != 1; v = parent_node[v]) {
            int u = parent_node[v];
            flow_net[u][v] += 1;
            flow_net[v][u] -= 1;
        }
        min_cut++;
    }

    dfs_reach(1, n);

    printf("%d\n", min_cut);
    for (int i = 0; i < m; i++) {
        int u = orig_u[i], v = orig_v[i];
        if ((vis[u] && !vis[v]) || (vis[v] && !vis[u])) {
            printf("%d %d\n", u, v);
        }
    }

    return 0;
}

