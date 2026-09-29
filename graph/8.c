#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* head[MAXN];
int color[MAXN];

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

int bfs(int start) {
    int queue[MAXN], q_head = 0, q_tail = 0;
    
    queue[q_tail++] = start;
    color[start] = 1;

    while (q_head < q_tail) {
        int u = queue[q_head++];
        for (Edge* curr = head[u]; curr; curr = curr->next) {
            int v = curr->to;
            if (color[v] == 0) {
                color[v] = (color[u] == 1) ? 2 : 1;
                queue[q_tail++] = v;
            } else if (color[v] == color[u]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int possible = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                possible = 0;
                break;
            }
        }
    }

    if (!possible) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%d%c", color[i], (i == n) ? '\n' : ' ');
        }
    }

    return 0;
}

