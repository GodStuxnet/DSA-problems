#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* head[MAXN];
int visited[MAXN];

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

void dfs(int u) {
    visited[u] = 1;
    for (Edge* curr = head[u]; curr; curr = curr->next) {
        if (!visited[curr->to]) dfs(curr->to);
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int roots[MAXN], count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            roots[count++] = i;
            dfs(i);
        }
    }

    printf("%d\n", count - 1);
    for (int i = 0; i < count - 1; i++) {
        printf("%d %d\n", roots[i], roots[i + 1]);
    }

    return 0;
}

