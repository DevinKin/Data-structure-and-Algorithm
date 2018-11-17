#include <stdio.h>
#include <stdlib.h>
#include "queuewitharray.h"


int
IsEmpty(Queue Q) {
    return Q->Size == 0;
}

int
IsFull(Queue Q) {
    return Q->Size == Q->Capacity;
}

Queue
CreateQueue(int MaxElements) {
    Queue Q;
    Q = malloc(sizeof(Queue));
    if (Q == NULL) {
        perror("create Queue failed!!!");
    }
    Q->Array = malloc(sizeof(ElementType)*MaxElements);
    if (Q->Array == NULL) {
        perror("create Array failed!!!");
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void
DisposeQueue(Queue Q) {
    free(Q->Array);
    free(Q);
}

void
MakeEmpty(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int
Succ(int Value, Queue Q) {
    if (++Value == Q->Capacity) {
        Value = 0;
    }
    return Value;
}

void
Enqueue(ElementType X, Queue Q) {
    if (IsFull(Q)) {
        perror("Full queue");
    } else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType
Front(Queue Q) {
    return Q->Array[Q->Front];
}

void
Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        perror("Empty Queue!!!");
    }
    Q->Size--;
    Q->Front = Succ(Q->Front, Q);
}

ElementType
FrontAndDequeue(Queue Q) {
    if (IsEmpty(Q)) {
        perror("Empty Queue!!!");
    }
    Q->Size--;
    ElementType res = Q->Array[Q->Front];
    Q->Front = Succ( Q->Front, Q );
    return res;
}


