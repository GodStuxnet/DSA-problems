#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    long long M, Q, N;
    if (scanf("%lld %lld %lld", &M, &Q, &N) != 3) return 0;

    long long *A = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    qsort(A, N, sizeof(long long), cmp);

    long long max_rating = 1;
    for (int i = 0; i < N; i++) {
        long long current_rating = 1;
        for (int j = i + 1; j < N; j++) {
            if ((A[j] - A[i]) % M == 0 && (A[j] - A[i]) <= 2 * Q * M) {
                current_rating++;
            }
        }
        if (current_rating > max_rating) {
            max_rating = current_rating;
        }
    }

    printf("\n%lld\n", max_rating);

    free(A);
    return 0;
}

