#include <stdio.h>
#include <stdlib.h>

int n, LOG;
int *bit;

void upd(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }

int kth(int k) {                 
    int pos = 0;
    for (int pw = LOG; pw; pw >>= 1) {
        if (pos + pw <= n && bit[pos + pw] < k) {
            pos += pw;
            k -= bit[pos];
        }
    }
    return pos + 1;
}

int main() {
    scanf("%d", &n);
    int *x = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);

    bit = malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) bit[i] = i & -i;

    LOG = 1;
    while (LOG * 2 <= n) LOG *= 2;

    int *out = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        int idx = kth(p);
        out[i] = x[idx];
        upd(idx, -1);
    }
    for (int i = 0; i < n; i++) printf("%d ", out[i]);
    printf("\n");
    return 0;
}
