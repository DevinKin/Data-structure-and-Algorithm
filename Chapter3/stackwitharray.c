#include "stackwitharray.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS (-1)
#define MinStackSize (5)


Stack
CreateStack(int MaxElements) {
    Stack S;

    if (MaxElements < MinStackSize) {
        perror("Stack size is too small");
    }

    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        perror("Out of space!!!");
    }

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL) {
        perror("Out of space!!!");
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

void
DisposeStack(Stack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}


int
IsEmpty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

void
MakeEmpty(Stack S) {
    S->TopOfStack = EmptyTOS;
}


void
Push(ElementType X, Stack S) {
    if (IsFull(S)) {
        perror("Full Stack");
    } else {
        S->Array[++S->TopOfStack] = X;
    }
}

int
IsFull(Stack S) {
    return S->TopOfStack == S->Capacity;
}


ElementType
Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack];
    }
    perror("Empty Stack");
    /* Return value used to avoid warning */
    return 0;
}

void
Pop(Stack S) {
    if (IsEmpty(S)) {
        perror("Empty Stack");
    } else {
        S->TopOfStack--;
    }
}


ElementType
TopAndPop(Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack--];
    }
    perror("Empty Stack");
    /* Return value used to avoid warning */
    return 0;
}
