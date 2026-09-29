#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int titles;
} Answer;

int counts[1000005];

int main() {
    int N;
    long long M;
    if (scanf("%d %lld", &N, &M) != 2) return 0;

    Answer* ans = (Answer*)malloc(N * sizeof(Answer));

    int best_ghost = 0;
    int max_titles = 0;

    for (int i = 0; i < N; i++) {
        int ghost_age;
        scanf("%d", &ghost_age);

        counts[ghost_age]++;

        if (counts[ghost_age] > max_titles) {
            max_titles = counts[ghost_age];
            best_ghost = ghost_age;
        } else if (counts[ghost_age] == max_titles) {
            if (ghost_age > best_ghost) {
                best_ghost = ghost_age;
            }
        }

        ans[i].age = best_ghost;
        ans[i].titles = max_titles;
    }

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", ans[i].age, ans[i].titles);
    }

    free(ans);
    return 0;
}

