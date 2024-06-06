#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct que {
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct que *q) {
    if (q->r == q->size - 1) {
        return 1;
    }
    return 0;
}

int isempty(struct que *q) {
    if (q->r == q->f) {
        return 1;
    }
    return 0;
}

void enque(struct que *q, int val) {
    if (isfull(q)) {
        printf("This queue is full...\n");
    } else {
        if (q->f == -1) {
            q->f = 0;
        }
        q->r++;
        q->arr[q->r] = val;
    }
}

// TODO: Implement the deque function

int main() {
    struct que q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

//bfs implementation


    return 0;
}
