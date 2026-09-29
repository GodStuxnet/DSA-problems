#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* head[MAXN];
int dp[MAXN][2];

void add_edge(int u, int v) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v;
    e1->next = head[u];
    head[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u;
    e2->next = head[v];
    head[v] = e2;
}

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = 0;

    int sum_max = 0;
    for (Edge* curr = head[u]; curr; curr = curr->next) {
        int v = curr->to;
        if (v != p) {
            dfs(v, u);
            int best_v = (dp[v][0] > dp[v][1]) ? dp[v][0] : dp[v][1];
            sum_max += best_v;
        }
    }

    dp[u][0] = sum_max;

    for (Edge* curr = head[u]; curr; curr = curr->next) {
        int v = curr->to;
        if (v != p) {
            int best_v = (dp[v][0] > dp[v][1]) ? dp[v][0] : dp[v][1];
            int candidate = sum_max - best_v + 1 + dp[v][0];
            if (candidate > dp[u][1]) {
                dp[u][1] = candidate;
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    dfs(1, 0);

    int ans = (dp[1][0] > dp[1][1]) ? dp[1][0] : dp[1][1];
    printf("%d\n", ans);

    return 0;
}
