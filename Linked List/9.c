#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void display(struct node *start) {
    printf("[h]=>");
    struct node *temp = start;
    if (start == NULL) {
        printf("[h]\n");
        return;
    }
    do {
        printf("%d=>", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("[h]\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val = i+1;
        //scanf("%d", &val);
        insert(val);
    }

    printf("Complete linked_list:\n");
    display(head);

    struct node *oddHead = NULL, *oddTail = NULL;
    struct node *evenHead = NULL, *evenTail = NULL;

    struct node *temp = head;
    int pos = 1;
    for (int i = 0; i < n; i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = temp->data;
        newNode->next = NULL;

        if (pos % 2 != 0) {
            if (oddHead == NULL) { oddHead = newNode; oddTail = newNode; }
            else { oddTail->next = newNode; oddTail = newNode; }
        } else {
            if (evenHead == NULL) { evenHead = newNode; evenTail = newNode; }
            else { evenTail->next = newNode; evenTail = newNode; }
        }

        temp = temp->next;
        pos++;
    }

    if (oddTail) oddTail->next = oddHead;
    if (evenTail) evenTail->next = evenHead;

    printf("Odd:\n");
    display(oddHead);

    printf("Even:\n");
    display(evenHead);

    return 0;
}