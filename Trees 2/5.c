#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* code = (int*)malloc((n - 2) * sizeof(int));
    int* degree = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) degree[i] = 1;

    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &code[i]);
        degree[code[i]]++;
    }

    int ptr = 1;
    while (degree[ptr] != 1) ptr++;
    int leaf = ptr;

    int* u_arr = (int*)malloc((n - 1) * sizeof(int));
    int* v_arr = (int*)malloc((n - 1) * sizeof(int));

    for (int i = 0; i < n - 2; i++) {
        int v = code[i];
        u_arr[i] = leaf;
        v_arr[i] = v;

        degree[v]--;
        if (degree[v] == 1 && v < ptr) {
            leaf = v;
        } else {
            ptr++;
            while (degree[ptr] != 1) ptr++;
            leaf = ptr;
        }
    }

    u_arr[n - 2] = leaf;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1 && i != leaf) {
            v_arr[n - 2] = i;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        printf("%d %d\n", u_arr[i], v_arr[i]);
    }

    free(code);
    free(degree);
    free(u_arr);
    free(v_arr);
    return 0;
}

