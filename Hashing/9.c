#include <stdio.h>
#include <stdlib.h>

int count_divisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i * i != n) count++;
        }
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int div_count[1005] = {0};
    for (int i = 0; i < n; i++) {
        int d = count_divisors(a[i]);
        if (d <= 1000) div_count[d]++;
    }

    long long total_pairs = 0;
    for (int i = 0; i <= 1000; i++) {
        if (div_count[i] > 1) {
            long long cnt = div_count[i];
            total_pairs += (cnt * (cnt - 1)) / 2;
        }
    }

    printf("\n%lld\n", total_pairs);

    free(a);
    return 0;
}

