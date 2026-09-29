#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    long long spendings[10000];
    int count;
} Festival;

int cmp_desc(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

void solve_case() {
    int n;
    if (scanf("%d", &n) != 1) return;

    Festival *fest = (Festival *)calloc(100, sizeof(Festival));
    if (!fest) return;

    int fest_cnt = 0;

    for (int i = 0; i < n; i++) {
        char name[15];
        long long val;
        scanf("%s %lld", name, &val);

        int found = -1;
        for (int j = 0; j < fest_cnt; j++) {
            if (strcmp(fest[j].name, name) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            fest[found].spendings[fest[found].count++] = val;
        } else {
            strcpy(fest[fest_cnt].name, name);
            fest[fest_cnt].spendings[0] = val;
            fest[fest_cnt].count = 1;
            fest_cnt++;
        }
    }

    char best_name[15] = "";
    long long max_sum = -1;

    for (int i = 0; i < fest_cnt; i++) {
        qsort(fest[i].spendings, fest[i].count, sizeof(long long), cmp_desc);

        long long current_sum = 0;
        int limit = fest[i].count < 3 ? fest[i].count : 3;
        for (int k = 0; k < limit; k++) {
            current_sum += fest[i].spendings[k];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            strcpy(best_name, fest[i].name);
        } else if (current_sum == max_sum) {
            if (strcmp(fest[i].name, best_name) < 0) {
                strcpy(best_name, fest[i].name);
            }
        }
    }

    printf("\n%s %lld\n", best_name, max_sum);
    free(fest);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    for (int i = 0; i < t; i++) {
        solve_case();
    }
    return 0;
}

