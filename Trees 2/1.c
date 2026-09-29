#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge *head1[MAXN], *head2[MAXN];

void add_edge(Edge** head, int u, int v) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->next = head[u];
    head[u] = e;
}

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char* get_canonical(int u, int p, Edge** head) {
    int child_count = 0;
    Edge* curr = head[u];
    while (curr) {
        if (curr->to != p) child_count++;
        curr = curr->next;
    }

    if (child_count == 0) {
        char* res = (char*)malloc(3 * sizeof(char));
        strcpy(res, "()");
        return res;
    }

    char** children = (char**)malloc(child_count * sizeof(char*));
    int idx = 0;
    int total_len = 0;

    curr = head[u];
    while (curr) {
        if (curr->to != p) {
            children[idx] = get_canonical(curr->to, u, head);
            total_len += strlen(children[idx]);
            idx++;
        }
        curr = curr->next;
    }

    qsort(children, child_count, sizeof(char*), compare_strings);

    char* res = (char*)malloc((total_len + 3) * sizeof(char));
    res[0] = '(';
    res[1] = '\0';

    for (int i = 0; i < child_count; i++) {
        strcat(res, children[i]);
        free(children[i]);
    }
    strcat(res, ")");
    free(children);

    return res;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    int* results = (int*)malloc(t * sizeof(int));

    for (int test = 0; test < t; test++) {
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            head1[i] = NULL;
            head2[i] = NULL;
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(head1, u, v);
            add_edge(head1, v, u);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(head2, u, v);
            add_edge(head2, v, u);
        }

        char* repr1 = get_canonical(1, 0, head1);
        char* repr2 = get_canonical(1, 0, head2);

        results[test] = (strcmp(repr1, repr2) == 0);

        free(repr1);
        free(repr2);
    }

    for (int test = 0; test < t; test++) {
        if (results[test]) printf("YES\n");
        else printf("NO\n");
    }

    free(results);
    return 0;
}

