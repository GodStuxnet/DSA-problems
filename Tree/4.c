#include <stdio.h>
#include <string.h>

#define MAXN 1001
#define MAXT 105

int adj[MAXN][MAXN], deg[MAXN], color[MAXN], queue[MAXN];
char res[MAXT][MAXN + 5];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) deg[i] = 0, color[i] = -1;
        for (int i = 1; i <= n; i++) {
            int k, f;
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &f);
                adj[i][deg[i]++] = f;
                adj[f][deg[f]++] = i;
            }
        }
        int ok = 1;
        for (int s = 1; s <= n && ok; s++) {
            if (color[s] != -1) continue;
            int head = 0, tail = 0;
            color[s] = 0;
            queue[tail++] = s;
            while (head < tail && ok) {
                int u = queue[head++];
                for (int j = 0; j < deg[u]; j++) {
                    int v = adj[u][j];
                    if (color[v] == -1) { color[v] = 1 - color[u]; queue[tail++] = v; }
                    else if (color[v] == color[u]) { ok = 0; break; }
                }
            }
        }
        if (!ok) strcpy(res[t], "-1");
        else {
            for (int i = 1; i <= n; i++) res[t][i-1] = color[i] ? 'R' : 'L';
            res[t][n] = '\0';
        }
    }
    for (int t = 0; t < T; t++) printf("%s\n", res[t]);
    return 0;
}

