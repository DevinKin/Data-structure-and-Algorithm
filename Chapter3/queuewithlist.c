#include "queuewithlist.h"
#include <stdio.h>
#include <stdlib.h>


int
IsEmpty(Queue Q) {
    return Q->Size == 0;
}

Queue
CreateQueue() {
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        perror("create queue fail!!!");
    }
    Q->Size = 0;
    Q->Front = malloc(sizeof(struct Node));
    if (Q->Front == NULL) {
        printf("create front fail");
        exit(-1);
    }
    Q->Rear = Q->Front;
    Q->Front->Next = NULL;
    printf("创建队列成功\n");
    return Q;
}

void
DisposeQueue(Queue Q) {
    Pnode n = Q->Front;
    Pnode tmp = n;
    while (n != NULL) {
        tmp = n->Next;
        free(n);
        n = tmp;
    }
    free(Q);
    printf("销毁队列成功\n");
}


void
Enqueue(ElementType X, Queue Q) {
    Pnode P;
    P = malloc(sizeof(struct Node));
    if (P == NULL) {
        printf("create node fail");
        exit(-1);
    }
    P->Element = X;
    P->Next = Q->Rear->Next;
    Q->Rear->Next = P;
    Q->Rear = Q->Rear->Next;
    Q->Size++;
}

void
Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty Queue!!!");
        exit(-1);
    }
    Q->Front = Q->Front->Next;
    Q->Size--;
}

ElementType
FrontAndDequeue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty Queue!!!");
        exit(-1);
    }
    ElementType res = Q->Front->Element;
    Q->Front = Q->Front->Next;
    Q->Size--;
    return res;
}
