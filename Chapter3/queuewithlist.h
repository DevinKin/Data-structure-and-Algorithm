#ifndef _QUEUEWITHLIST_H
#define _QUEUEWITHLIST_H

struct Queue;
struct Node;
typedef struct Node* Pnode;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

struct QueueRecord {
    Pnode Front;
    Pnode Rear;
    int Size;
};

struct Node {
    ElementType Element;
    struct Node *Next;
};

#endif
