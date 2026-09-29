#include <stdio.h>
#include <stdlib.h>

#define MAXM 200005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* head[MAXM];
int disc[MAXM], low[MAXM], scc[MAXM], in_stack[MAXM], stack[MAXM];
int timer = 0, top = 0, scc_count = 0;

void add_edge(int u, int v) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->next = head[u];
    head[u] = e;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void tarjan(int u) {
    disc[u] = low[u] = ++timer;
    stack[top++] = u;
    in_stack[u] = 1;

    for (Edge* curr = head[u]; curr; curr = curr->next) {
        int v = curr->to;
        if (!disc[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        scc_count++;
        while (1) {
            int v = stack[--top];
            in_stack[v] = 0;
            scc[v] = scc_count;
            if (u == v) break;
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        char type1, type2;
        int x, y;
        scanf(" %c %d %c %d", &type1, &x, &type2, &y);

        int pos_u = 2 * x + 1, neg_u = 2 * x;
        int pos_v = 2 * y + 1, neg_v = 2 * y;

        int u = (type1 == '+') ? pos_u : neg_u;
        int not_u = (type1 == '+') ? neg_u : pos_u;
        int v = (type2 == '+') ? pos_v : neg_v;
        int not_v = (type2 == '+') ? neg_v : pos_v;

        add_edge(not_u, v);
        add_edge(not_v, u);
    }

    for (int i = 2; i <= 2 * m + 1; i++) {
        if (!disc[i]) tarjan(i);
    }

    for (int i = 1; i <= m; i++) {
        if (scc[2 * i] == scc[2 * i + 1]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (scc[2 * i + 1] < scc[2 * i]) {
            printf("+%c", (i == m) ? '\n' : ' ');
        } else {
            printf("-%c", (i == m) ? '\n' : ' ');
        }
    }

    return 0;
}

