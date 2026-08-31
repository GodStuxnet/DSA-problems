#include <stdio.h>
#define max 3000
int a[max];
int F[max], G[max];

int main()
{
    int n, i, j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        F[i]=-1;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                F[i]=j;
                break;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        G[i]=-1;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                G[i]=j;
                break;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(F[i]==-1 || G[F[i]]==-1)
            printf("-1");
        else
            printf("%d", a[G[F[i]]]);
        if(i!=n-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}