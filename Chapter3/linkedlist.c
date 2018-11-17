#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/* Place in the implementation file  */
struct Node
{
    int Element;
    Position Next;
};


/* Return true if L is empty */
int
IsEmpty(List L) {
    return L->Next == NULL;
}

List
MakeEmpty() {
    List emptylist;

    emptylist = malloc(sizeof(struct Node));

    if (emptylist == NULL) {
        perror("out of memory");
    }

    return emptylist;
}

/* Return true if P is the last position in list i */
/* Parameter L is unused in this implementation */
int
IsLast(Position P, List L) {
    return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position
Find(int X, List L) {
    Position P;

    P = L->Next;

    while (P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}


/* Delete first occurrence of X from a list */
/* Assume use of a header Node */
void
Delete(int X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X, L);

    /* Assumption of header use */
    /* X is found; delete it */
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        /* Bypass deleted cell */
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}


/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assume a header */
Position
FindPrevious(int X, List L) {
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}


/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void
Insert(int X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        perror("Out of space!!!");
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}


/* Correct DeleteList algorithm */
void
DeleteList(List L) {
    Position P, Tmp;

    /* Header assumed */
    P = L->Next;
    L->Next = NULL;
    while(P != NULL) {
        Tmp = P->Next;
        // after free P we can't use P
        free(P);
        P = Tmp;
    }
}


Position
Header(List L) {
    return L;
}

Position
First(List L) {
    return L->Next;
}

Position
Advance(Position P) {
    return P->Next;
}

int Retrieve(Position P) {
    return P->Element;
}


void
printLinkedList(List L) {
    // skip header
    Position P = L->Next;
    printf("[ ");
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("]\n");
}


void
fromArray(List L, int args[], int size) {
    if (L == NULL) {
        L = MakeEmpty();
    }
    Position P = L;
    Position tmp;
    for (int i = 0; i < size; i++) {
        tmp = malloc(sizeof(struct Node));
        if (tmp == NULL) {
            perror("out of memory");
        }
        tmp->Element = args[i];
        P->Next = tmp;
        P = P->Next;
    }
}

