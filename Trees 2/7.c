#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100005

int freq[MAXVAL];

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int max_val = 0;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        freq[val]++;
        if (val > max_val) max_val = val;
    }

    int Q;
    scanf("%d", &Q);

    int* sizes = (int*)malloc(Q * sizeof(int));

    for (int q = 0; q < Q; q++) {
        int val;
        scanf("%d", &val);

        if (val > max_val) {
            freq[val]++;
            max_val = val;
        } else if (val < max_val && freq[val] < 2) {
            freq[val]++;
        }

        int current_size = 0;
        for (int i = 0; i < MAXVAL; i++) {
            current_size += freq[i];
        }
        sizes[q] = current_size;
    }

    for (int q = 0; q < Q; q++) {
        printf("%d\n", sizes[q]);
    }

    for (int i = 1; i <= max_val; i++) {
        if (freq[i] > 0) printf("%d ", i);
    }
    for (int i = max_val - 1; i >= 1; i--) {
        if (freq[i] == 2) printf("%d ", i);
    }
    printf("\n");

    free(sizes);
    return 0;
}

