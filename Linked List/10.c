#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void deleteFirstK(int k) {
    for (int i = 0; i < k && start != NULL; i++) {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void display() {
    printf("Linked List:");
    struct node *ptr = start;
    while (ptr != NULL) {
        printf("->%d", ptr->data);
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

    int k;
    scanf("%d", &k);

    deleteFirstK(k);
    display();

    return 0;
}