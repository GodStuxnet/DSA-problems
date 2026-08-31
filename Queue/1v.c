#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1;

    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return val;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    long long biggest = -1, second = -1, third = -1;

    for (int i = 0; i < n; i++) {
        int big;
        scanf("%d", &big);

        enqueue(&q, big);
        int val = dequeue(&q);

        if (biggest < val) {
            third = second;
            second = biggest;
            biggest = val;
        } else if (second < val) {
            third = second;
            second = val;
        } else if (third < val) {
            third = val;
        }

        if (second == -1 || third == -1)
            printf("-1\n");
        else
            printf("%lld\n", biggest * second * third);
    }

    return 0;
}