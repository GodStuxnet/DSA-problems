#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

ll frequency(ll i)
{
    ll root = (ll)sqrt((double)i);

    while ((root + 1) * (root + 1) <= i)
        root++;

    while (root * root > i)
        root--;

    return i * root + (i + 1) / 2;
}

ll findValue(ll *prefix, ll n, ll pos)
{
    ll low = 1;
    ll high = n;

    while (low < high)
    {
        ll mid = low + (high - low) / 2;

        if (prefix[mid] >= pos)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int Q;
    scanf("%d", &Q);

    ll *L = malloc(sizeof(ll) * Q);
    ll *R = malloc(sizeof(ll) * Q);

    ll maxR = 0;

    for (int i = 0; i < Q; i++)
    {
        scanf("%lld %lld", &L[i], &R[i]);

        if (R[i] > maxR)
            maxR = R[i];
    }

    ll capacity = 1024;

    ll *prefix = malloc(sizeof(ll) * capacity);

    prefix[0] = 0;

    ll n = 0;

    while (prefix[n] < maxR)
    {
        n++;

        if (n >= capacity)
        {
            capacity *= 2;
            prefix = realloc(prefix, sizeof(ll) * capacity);
        }

        prefix[n] = prefix[n - 1] + frequency(n);
    }

    for (int i = 0; i < Q; i++)
    {
        ll leftValue = findValue(prefix, n, L[i]);
        ll rightValue = findValue(prefix, n, R[i]);

        printf("%lld\n", rightValue - leftValue + 1);
    }

    free(L);
    free(R);
    free(prefix);

    return 0;
}
