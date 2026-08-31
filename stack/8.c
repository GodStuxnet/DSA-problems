#include <stdio.h>
#define max 10000

long long arr[max];
long long st[max];
int nge[max];
int stk[max];

int main()
{
    int n, i, j, top=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    for(i=n-1;i>=0;i--)
    {
        while(top>=0)
        {
            j = stk[top];
            if(arr[i]<arr[j])
                break;
            top--;
        }
        nge[i] = (top>=0) ? stk[top] : -1;
        top++;
        stk[top]=i;
    }

    long long maxXor=0;
    for(i=n-1;i>=0;i--)
    {
        j = nge[i];
        st[i] = (j==-1) ? arr[i] : arr[i]^st[j];
        if(st[i]>maxXor)
            maxXor=st[i];
    }

    printf("%lld\n", maxXor);
    return 0;
}