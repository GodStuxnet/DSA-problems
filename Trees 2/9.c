#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* head[MAXN];
char node_char[MAXN];
int in_time[MAXN], out_time[MAXN];
int timer = 0;

int pref[MAXN][26];
int euler_char[MAXN];

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
    timer++;
    in_time[u] = timer;
    euler_char[timer] = node_char[u] - 'a';

    Edge* curr = head[u];
    while (curr) {
        if (curr->to != p) dfs(curr->to, u);
        curr = curr->next;
    }
    out_time[u] = timer;
}

int main() {
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2) return 0;

    for (int i = 1; i <= N; i++) head[i] = NULL;

    scanf("%s", node_char + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c < 26; c++) pref[i][c] = pref[i - 1][c];
        pref[i][euler_char[i]]++;
    }

    int* answers = (int*)malloc(Q * sizeof(int));

    for (int q = 0; q < Q; q++) {
        int u;
        char c;
        scanf("%d %c", &u, &c);

        int char_idx = c - 'a';
        answers[q] = pref[out_time[u]][char_idx] - pref[in_time[u] - 1][char_idx];
    }

    for (int q = 0; q < Q; q++) {
        printf("%d\n", answers[q]);
    }

    free(answers);
    return 0;
}

