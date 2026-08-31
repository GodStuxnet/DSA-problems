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

void insertBefore(int key, int value) {
    struct node *p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = value;

    struct node *p2 = NULL;
    struct node *curr = start;

    while (curr != NULL && curr->data != key) {
        p2 = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node not found!\n");
        free(p1);
        return;
    }

    p1->next = curr;
    if (p2 == NULL) {
        start = p1;
    } else {
        p2->next = p1;
    }
}

void display() {
    struct node *temp = start;
    printf("Linked List:");
    while (temp != NULL) {
        printf("->%d", temp->data);
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

    int key, value;
    scanf("%d", &key);
    scanf("%d", &value);

    insertBefore(key, value);
    display();

    return 0;
}