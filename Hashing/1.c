#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve() {
    int t;
    if (scanf("%d", &t) != 1) return;

    int *a = (int *)malloc(t * sizeof(int));
    int *b = (int *)malloc(t * sizeof(int));

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    double phi = (1.0 + sqrt(5.0)) / 2.0;

    for (int i = 0; i < t; i++) {
        int x = a[i];
        int y = b[i];

        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        int k = y - x;
        int expected_x = (int)(k * phi);

        if (x == expected_x) {
            printf("Sami\n");
        } else {
            printf("Canthi\n");
        }
    }

    free(a);
    free(b);
}

int main() {
    solve();
    return 0;
}

