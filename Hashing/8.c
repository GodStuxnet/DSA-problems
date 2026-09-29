#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int type;
    int val;
} Query;

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    Query *queries = (Query *)malloc(q * sizeof(Query));
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &queries[i].type, &queries[i].val);
    }

    int *arr = (int *)calloc(n + 1, sizeof(int));
    int *results = (int *)malloc(q * sizeof(int));
    int res_cnt = 0;

    for (int i = 0; i < q; i++) {
        if (queries[i].type == 1) {
            int k = queries[i].val;
            arr[k] = -1;
        } else if (queries[i].type == 2) {
            int y = queries[i].val;
            int found = -1;
            for (int idx = y; idx <= n; idx++) {
                if (arr[idx] == -1) {
                    found = idx;
                    break;
                }
            }
            results[res_cnt++] = found;
        }
    }

    printf("\n");
    for (int i = 0; i < res_cnt; i++) {
        printf("%d\n", results[i]);
    }

    free(queries);
    free(arr);
    free(results);
    return 0;
}

