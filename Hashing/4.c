#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int *b_crush;
    int *g_crush;
} TestCase;

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    TestCase *tests = (TestCase *)malloc(t * sizeof(TestCase));

    for (int i = 0; i < t; i++) {
        scanf("%d", &tests[i].n);
        int n = tests[i].n;

        tests[i].b_crush = (int *)malloc((n + 1) * sizeof(int));
        tests[i].g_crush = (int *)malloc((n + 1) * sizeof(int));

        for (int j = 1; j <= n; j++) scanf("%d", &tests[i].b_crush[j]);
        for (int j = 1; j <= n; j++) scanf("%d", &tests[i].g_crush[j]);
    }

    for (int i = 0; i < t; i++) {
        int n = tests[i].n;
        int *b_crush = tests[i].b_crush;
        int *g_crush = tests[i].g_crush;

        int *b_beat = (int *)calloc(n + 1, sizeof(int));
        int *g_beat = (int *)calloc(n + 1, sizeof(int));

        for (int b = 1; b <= n; b++) {
            int g = b_crush[b];
            int target_b = g_crush[g];
            if (b != target_b) {
                b_beat[target_b]++;
            }
        }

        for (int g = 1; g <= n; g++) {
            int b = g_crush[g];
            int target_g = b_crush[b];
            if (g != target_g) {
                g_beat[target_g]++;
            }
        }

        int max_beatings = 0;
        for (int j = 1; j <= n; j++) {
            if (b_beat[j] > max_beatings) max_beatings = b_beat[j];
            if (g_beat[j] > max_beatings) max_beatings = g_beat[j];
        }

        int mutual_pairs = 0;
        for (int b = 1; b <= n; b++) {
            int g = b_crush[b];
            if (g_crush[g] == b) {
                mutual_pairs++;
            }
        }

        printf("\n%d %d\n", max_beatings, mutual_pairs);

        free(b_crush);
        free(g_crush);
        free(b_beat);
        free(g_beat);
    }

    free(tests);
    return 0;
}

