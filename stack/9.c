#include <stdio.h>

int q[100005];
int front=0, rear=0;

void push(int val)
{
    int s = rear-front;
    q[rear++] = val;
    while(s--)
    {
        q[rear++] = q[front++];
    }
}

void pop()
{
    front++;
}

int top()
{
    return q[front];
}

int main()
{
    int n, m, x, i;
    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }

    printf("top of element %d\n", top());

    for(i=0;i<m;i++)
        pop();

    printf("top of element %d\n", top());

    return 0;
}