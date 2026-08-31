#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("No data in the queue.\n");
        return;
    }
    struct node *temp = front;
    front = front->next;
    free(temp);
}

void print() {
    if (front == NULL) {
        printf("No data in the queue.\n");
        return;
    }
    struct node *ptr = front;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    int data;
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    print();
    dequeue();
    print();

    return 0;
}