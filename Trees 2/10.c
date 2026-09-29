#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 1000005

int freq[MAXVAL];

int main() {
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;

    int max_seats = 0;
    for (int i = 0; i < M; i++) {
        int seats;
        scanf("%d", &seats);
        freq[seats]++;
        if (seats > max_seats) max_seats = seats;
    }

    long long total_revenue = 0;
    int current_seats = max_seats;

    while (N > 0 && current_seats > 0) {
        if (freq[current_seats] == 0) {
            current_seats--;
            continue;
        }

        int count = freq[current_seats];
        if (N >= count) {
            total_revenue += (long long)count * current_seats;
            N -= count;
            freq[current_seats - 1] += count;
            freq[current_seats] = 0;
            current_seats--;
        } else {
            total_revenue += (long long)N * current_seats;
            N = 0;
        }
    }

    printf("%lld\n", total_revenue);
    return 0;
}

