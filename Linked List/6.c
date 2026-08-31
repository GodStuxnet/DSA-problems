#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void reverse() {
    struct node *prev = NULL, *cur = start, *next;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    start = prev;
}

int getNodeAtIndex(int index) {
    struct node *ptr = start;
    int i = 0;
    while (ptr != NULL) {
        if (i == index) return ptr->data;
        ptr = ptr->next;
        i++;
    }
    return -1;
}

void display() {
    printf("Linked list:");
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("-->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *last = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    int index;
    scanf("%d", &index);

    reverse();
    display();

    printf("Node at index=%d:%d\n", index, getNodeAtIndex(index));

    return 0;
}