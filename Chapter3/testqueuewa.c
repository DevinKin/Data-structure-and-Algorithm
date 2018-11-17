#include "queuewitharray.h"
#include <stdio.h>

int main(void) {
    int N = 10;
    Queue Q = CreateQueue(N);
    for (int i = 0; i < N; i++) {
        Enqueue(i, Q);
    }

    Dequeue(Q);
    for (int i = 0; i < N - 1; i++) {
        int front = FrontAndDequeue(Q);
        printf("%d ", front );
    }
    printf("\n");
    DisposeQueue(Q);
}
