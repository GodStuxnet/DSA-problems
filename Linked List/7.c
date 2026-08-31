#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
int n, val;

void create()
{
    int i, x;
    struct node *newnode, *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        if(head==NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void del()
{
    struct node *p1;
    int found=0;
    p1 = head;
    while(p1!=NULL)
    {
        if(p1->data==val)
        {
            found=1;
            break;
        }
        p1=p1->next;
    }
    if(found==0)
    {
        printf("Invalid Node! Linked List:");
        p1=head;
    }
    else
    {
        head=p1;
        printf("Linked List:");
        p1=head;
    }
    while(p1!=NULL)
    {
        printf("->%d",p1->data);
        p1=p1->next;
    }
}

int main()
{
    scanf("%d",&n);
    create();
    scanf("%d",&val);
    del();
    return 0;
}