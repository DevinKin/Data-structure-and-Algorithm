#include "queuewithlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N = 10;
    Queue Q = CreateQueue(N);
    for (int i = 0; i < N; i++) {
        Enqueue(i, Q);
    }

    for (int i = 0; i < N; i++) {
        int front = FrontAndDequeue(Q);
        printf("%d ", front );
    }
    printf("\n");
    DisposeQueue(Q);
}
