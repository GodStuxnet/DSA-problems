#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    front++;
}

void disp() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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

    printf("Dequeuing elements:\n");
    while (front <= rear) {
        dequeue();
        disp();
    }

    return 0;
}