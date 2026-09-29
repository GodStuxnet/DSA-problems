#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[5005];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}

int compare_edges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e2->w - e1->w;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    int* results = (int*)malloc(T * sizeof(int));

    for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        Edge* edges = (Edge*)malloc(M * sizeof(Edge));
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        qsort(edges, M, sizeof(Edge), compare_edges);

        for (int i = 1; i <= N; i++) parent[i] = i;

        int mst_weight = 0;
        int edges_count = 0;

        for (int i = 0; i < M; i++) {
            if (find_set(edges[i].u) != find_set(edges[i].v)) {
                union_sets(edges[i].u, edges[i].v);
                mst_weight += edges[i].w;
                edges_count++;
            }
        }

        results[t] = mst_weight;
        free(edges);
    }

    for (int t = 0; t < T; t++) {
        printf("%d\n", results[t]);
    }

    free(results);
    return 0;
}

