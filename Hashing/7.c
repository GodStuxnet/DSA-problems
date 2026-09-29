#include <stdio.h>
#include <stdlib.h>

int cmp_ll(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    int total_subarrays = n * (n + 1) / 2;
    long long *sums = (long long *)malloc(total_subarrays * sizeof(long long));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += a[j];
            sums[idx++] = current_sum;
        }
    }

    qsort(sums, total_subarrays, sizeof(long long), cmp_ll);

    long long unique_sum = 0;
    for (int i = 0; i < total_subarrays; i++) {
        if (i == 0 || sums[i] != sums[i - 1]) {
            unique_sum += sums[i];
        }
    }

    printf("%lld\n", unique_sum);

    free(a);
    free(sums);
    return 0;
}

