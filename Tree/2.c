#include <stdio.h>

#define MAXN 100005

int pre[MAXN], in[MAXN], pos[MAXN], post[MAXN];
int cnt = 0;

void solve(int preL, int inL, int inR)
{
    if (inL > inR) return;
    int root = pre[preL];
    int idx = pos[root];
    int leftSize = idx - inL;
    solve(preL + 1, inL, idx - 1);
    solve(preL + 1 + leftSize, idx + 1, inR);
    post[cnt++] = root;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) { scanf("%d", &in[i]); pos[in[i]] = i; }
    solve(0, 0, n - 1);
    for (int i = 0; i < cnt; i++) {
        if (i) printf(" ");
        printf("%d", post[i]);
    }
    printf("\n");
    return 0;
}

