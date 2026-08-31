#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void insertEnd(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
        return;
    }
    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printReverse(struct node *node) {
    if (node == NULL) return;
    printReverse(node->next);
    printf("%d ", node->data);
}

void display() {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(val);
    }

    printReverse(start);
    printf("\n");

    display();

    return 0;
}