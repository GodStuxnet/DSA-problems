#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_Data(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void delete_Alt(struct node **head) {
    if (*head == NULL) return;

    struct node *cur = *head;
    while (cur != NULL && cur->next != NULL) {
        struct node *temp = cur->next;
        cur->next = temp->next;
        free(temp);
        cur = cur->next;
    }
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL;

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            insert_Data(&head, i);
        }
    }

    display(head);

    return 0;
}