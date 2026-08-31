#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200005

int n, m, size;
char s[MAXN];
int bit_[MAXN];

int len_[2*MAXN], firstb[2*MAXN], lastb[2*MAXN];
int prelen[2*MAXN], suflen[2*MAXN], maxlen[2*MAXN];

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

void pull(int k) {
    int lc = 2*k, rc = 2*k+1;
    len_[k] = len_[lc] + len_[rc];
    firstb[k] = firstb[lc];
    lastb[k] = lastb[rc];

    int same = (lastb[lc] == firstb[rc]);

    prelen[k] = prelen[lc] + (same && prelen[lc] == len_[lc]) * prelen[rc];
    suflen[k] = suflen[rc] + (same && suflen[rc] == len_[rc]) * suflen[lc];

    int mid = same * (suflen[lc] + prelen[rc]);

    maxlen[k] = maxlen[lc];
    maxlen[k] = maxlen[rc] > maxlen[k] ? maxlen[rc] : maxlen[k];
    maxlen[k] = mid > maxlen[k] ? mid : maxlen[k];
}

void build() {
    size = 1;
    while (size < n) size *= 2;

    for (int i = 0; i < size; i++) {
        int leaf = size + i;
        int val = (i < n) ? bit_[i+1] : -2;
        len_[leaf] = 1;
        firstb[leaf] = lastb[leaf] = val;
        prelen[leaf] = suflen[leaf] = maxlen[leaf] = 1;
    }
    for (int k = size - 1; k >= 1; k--)
        pull(k);
}

void update(int x) {
    int leaf = size + x - 1;
    bit_[x] ^= 1;
    firstb[leaf] = lastb[leaf] = bit_[x];

    int k = leaf / 2;
    while (k >= 1) {
        pull(k);
        k /= 2;
    }
}

int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    for (int i = 1; i <= n; i++)
        bit_[i] = s[i] - '0';

    build();

    scanf("%d", &m);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (!isEmpty(&q)) {
        int x = dequeue(&q);
        update(x);
        printf("%d ", maxlen[1]);
    }

    return 0;
}