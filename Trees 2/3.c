#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge *head[MAXN], *head_rev[MAXN];
int visited[MAXN];

void add_edge(int u, int v) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v;
    e1->next = head[u];
    head[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u;
    e2->next = head_rev[v];
    head_rev[v] = e2;
}

void dfs1(int u) {
    visited[u] = 1;
    Edge* curr = head[u];
    while (curr) {
        if (!visited[curr->to]) dfs1(curr->to);
        curr = curr->next;
    }
}

void dfs2(int u) {
    visited[u] = 1;
    Edge* curr = head_rev[u];
    while (curr) {
        if (!visited[curr->to]) dfs2(curr->to);
        curr = curr->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        head[i] = NULL;
        head_rev[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    dfs1(1);
    int unreached_forward = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unreached_forward = i;
            break;
        }
    }

    if (unreached_forward != -1) {
        printf("1\n");
        printf("1 %d\n", unreached_forward);
        return 0;
    }

    for (int i = 1; i <= n; i++) visited[i] = 0;
    dfs2(1);

    int unreached_backward = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            unreached_backward = i;
            break;
        }
    }

    if (unreached_backward != -1) {
        printf("1\n");
        printf("%d 1\n", unreached_backward);
    } else {
        printf("0\n");
    }

    return 0;
}

