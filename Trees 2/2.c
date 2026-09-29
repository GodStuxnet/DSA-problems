#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

int main() {
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2) return 0;

    long long* A = (long long*)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), compare_desc);

    long long* total_sum = (long long*)malloc(N * sizeof(long long));
    long long current_total = 0;
    for (int i = 0; i < N; i++) current_total += A[i];

    total_sum[0] = current_total;

    int L = 0, R = N - 1;
    for (int k = 1; k < N; k++) {
        long long diff = A[L] - A[R];
        current_total -= (A[L] + A[R]);
        current_total += diff;
        A[L] = diff;
        R--;
        total_sum[k] = current_total;
    }

    int* queries = (int*)malloc(Q * sizeof(int));
    for (int q = 0; q < Q; q++) {
        scanf("%d", &queries[q]);
    }

    for (int q = 0; q < Q; q++) {
        printf("%lld\n", total_sum[queries[q]]);
    }

    free(A);
    free(total_sum);
    free(queries);
    return 0;
}

