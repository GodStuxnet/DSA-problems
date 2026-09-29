#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=0;t<T;t++) {
        int n;
        long long d, x[1001];
        scanf("%d %lld", &n, &d);
        for (int i = 0; i < n; i++) scanf("%lld", &x[i]);
        for(int i=n-1;i>=0;i--) d = (d / x[i]) * x[i];
        printf("%lld\n", d);
    }
    return 0;
}

