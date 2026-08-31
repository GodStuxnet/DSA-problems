#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if (f == NULL) {
        f = n;
        r = n;
        r->next = f;
    } else {
        r->next = n;
        r = n;
        r->next = f;
    }
}

void display() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *ptr = f;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != f);
}

int main() {
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    display();

    return 0;
}