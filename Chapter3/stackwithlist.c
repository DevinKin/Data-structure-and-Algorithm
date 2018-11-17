#include "stackwithlist.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType Element;
    PtrNode Next;
};

int
IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;

    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        perror("out of memory");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void
MakeEmpty(Stack S) {
    if (S == NULL) {
        perror("Must use CreateStack first");
    } else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void
Push(ElementType X, Stack S) {
    PtrNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        perror("out of memory");
    } else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType
Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    printf("empty Stack");
    /* Return value used to avoid warning */
    return 0;
}

void
Pop(Stack S) {
    PtrNode FirstCell;
    if (IsEmpty(S)) {
        perror("Empty Stack");
    } else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void
DisposeStack(Stack S) {
    MakeEmpty(S);
    free(S);
}
