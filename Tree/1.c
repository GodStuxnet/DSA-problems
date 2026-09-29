#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int v)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

struct node *insert(struct node *root, int v)
{
    if (root == NULL) return newNode(v);
    if (v < root->data) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

int first = 1;
void preorder(struct node *root)
{
    if (root == NULL) return;
    if (!first) printf(" ");
    first = 0;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n, v;
    struct node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        root = insert(root, v);
    }
    preorder(root);
    return 0;
}

