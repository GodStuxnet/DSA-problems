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

void disp() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    int size;
    scanf("%d", &size);

    int data;
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        printf("Enqueuing %d\n", data);
        enqueue(data);
        disp();
    }

    return 0;
}