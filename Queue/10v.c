#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data, int l) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = data;
}

void reverse() {
    int i = front, j = rear;
    while (i < j) {
        int t = queue[i];
        queue[i] = queue[j];
        queue[j] = t;
        i++;
        j--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int i = 0, data;
    while (i < n) {
        scanf("%d", &data);
        enqueue(data, n);
        if(i == 0){
            printf("Queue:");
        }
        printf("%d ",data);
        i++;
    }
    
    printf("\n");

    reverse();

    printf("Reversed Queue:");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    return 0;
}