#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

int capacity[505][505], flow[505][505], parent_node[505];

int bfs(int s, int t, int n) {
    memset(parent_node, -1, sizeof(parent_node));
    parent_node[s] = s;
    int queue[505], head = 0, tail = 0;
    queue[tail++] = s;

    while (head < tail) {
        int u = queue[head++];
        if (u == t) break;
        for (int v = 1; v <= n; v++) {
            if (parent_node[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                parent_node[v] = u;
                queue[tail++] = v;
            }
        }
    }
    return parent_node[t] != -1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        capacity[a][b] += 1;
    }

    int max_flow = 0;
    while (bfs(1, n, n)) {
        for (int v = n; v != 1; v = parent_node[v]) {
            int u = parent_node[v];
            flow[u][v] += 1;
            flow[v][u] -= 1;
        }
        max_flow++;
    }

    printf("%d\n", max_flow);

    for (int i = 0; i < max_flow; i++) {
        int curr = 1;
        int route[505], r_len = 0;
        route[r_len++] = curr;

        while (curr != n) {
            for (int v = 1; v <= n; v++) {
                if (flow[curr][v] > 0) {
                    flow[curr][v] -= 1;
                    curr = v;
                    route[r_len++] = curr;
                    break;
                }
            }
        }

        printf("%d\n", r_len);
        for (int j = 0; j < r_len; j++) {
            printf("%d%c", route[j], (j == r_len - 1) ? '\n' : ' ');
        }
    }

    return 0;
}

