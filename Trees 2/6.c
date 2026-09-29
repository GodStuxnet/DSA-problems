#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long sum;
    long long lazy_a;
    long long lazy_d;
} Node;

Node tree[800020];
long long arr[200005];

void build(int node, int start, int end) {
    tree[node].lazy_a = 0;
    tree[node].lazy_d = 0;
    if (start == end) {
        tree[node].sum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

void apply(int node, int start, int end, long long a, long long d) {
    long long count = end - start + 1;
    tree[node].sum += count * a + d * count * (count - 1) / 2;
    tree[node].lazy_a += a;
    tree[node].lazy_d += d;
}

void push(int node, int start, int end) {
    if (tree[node].lazy_a == 0 && tree[node].lazy_d == 0) return;
    int mid = (start + end) / 2;
    long long left_count = mid - start + 1;

    apply(2 * node, start, mid, tree[node].lazy_a, tree[node].lazy_d);
    apply(2 * node + 1, mid + 1, end, tree[node].lazy_a + left_count * tree[node].lazy_d, tree[node].lazy_d);

    tree[node].lazy_a = 0;
    tree[node].lazy_d = 0;
}

void update(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        apply(node, start, end, start - l + 1, 1);
        return;
    }
    push(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r);
    update(2 * node + 1, mid + 1, end, l, r);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node].sum;
    push(node, start, end);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    build(1, 1, n);

    long long* outputs = (long long*)malloc(q * sizeof(long long));
    int out_count = 0;

    for (int i = 0; i < q; i++) {
        int type, a, b;
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1) {
            update(1, 1, n, a, b);
        } else {
            outputs[out_count++] = query(1, 1, n, a, b);
        }
    }

    for (int i = 0; i < out_count; i++) {
        printf("%lld\n", outputs[i]);
    }

    free(outputs);
    return 0;
}

