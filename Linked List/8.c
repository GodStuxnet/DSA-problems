#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head, int data) {
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

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void fold(struct node *head) {
    if (head == NULL || head->next == NULL) return;

    // Find middle
    struct node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct node *second = slow->next;
    slow->next = NULL;
    struct node *prev = NULL, *curr = second, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    second = prev;

    // Merge alternately
    struct node *first = head;
    while (second != NULL) {
        struct node *tmp1 = first->next;
        struct node *tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        create(&head, val);
    }

    printf("Link list data:");
    print(head);

    fold(head);

    printf("Link list data after fold:");
    print(head);

    return 0;
}