#include <stdio.h>

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    
    long long temp;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &temp);
    }

    long long ans = (n * (n - 1)) / 2;
    printf("%lld\n", ans);

    return 0;
}

