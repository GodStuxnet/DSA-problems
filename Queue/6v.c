#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enQueue(Queue *q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }
}

int deQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    return value;
}

void display(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in Circular Queue are:");
    Node *ptr = q->front;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != q->front);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Queue *q = createQueue();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enQueue(q, val);
    }

    display(q);

    int d1 = deQueue(q);
    printf("Deleted value = %d\n", d1);

    int d2 = deQueue(q);
    printf("Deleted value = %d", d2);

    display(q);

    return 0;
}