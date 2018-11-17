#include "cursor.h"
#include <stdio.h>

/* Place in implementation file */

struct Node CursorSpace[SpaceSize];


static Position
CursorAlloc(void) {
    Position P;

    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void
CursorFree(Position P) {
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

void
InitializeCursorSpace(void) {
    for (int i = 0; i < SpaceSize - 1; i++) {
        CursorSpace[i].Next = i + 1;
    }
    CursorSpace[SpaceSize - 1].Next = 0;
}


List
MakeEmpty(List L) {
    if (IsEmpty(L)) {
        return L;
    }

    Position p = CursorSpace[L].Next;
    Position tmp;
    while(p) {
        tmp = p;
        p = CursorSpace[p].Next;
        CursorFree(tmp);
    }
    return L;
}


/* Return true if L is empty */
int
IsEmpty(List L) {
    return CursorSpace[L].Next == 0;
}

/* Return true if P is the last position in list l */
/* Parameter L is unused in this implementation */
int
IsLast(Position P, List L) {
    return CursorSpace[P].Next == 0;
}

/* Return Position of X in L; 0 if not found */
/* Uses a header node */
Position
Find(ElementType X, List L) {
    Position P;
    P = CursorSpace[L].Next;
    while (P && CursorSpace[P].Element != X) {
        P = CursorSpace[P].Next;
    }
    return P;
}


/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void
Delete(ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    /* Assumption of header use */
    /* X is found; delete it */
    if (!IsLast(P, L)) {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}


Position
FindPrevious(ElementType X, const List L) {
    Position p, tmp;
    tmp = CursorSpace[L].Next;
    while(tmp && CursorSpace[tmp].Element != X) {
        // record
        p = tmp;
        tmp = CursorSpace[tmp].Next;
    }
    return p;
}


/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void
Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = CursorAlloc();
    if (TmpCell == 0) {
        perror("out of memory");
    }
    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}


void DeleteList(List L) {
    List head = MakeEmpty(L);
    CursorFree(head);
}

Position
Header(const List L) {
    return L;
}

Position
First(const List L) {
    return CursorSpace[L].Next;
}

Position
Advance(const Position P) {
    return CursorSpace[P].Next;
}

ElementType
Retireve(const Position P) {
    return CursorSpace[P].Element;
}

List
FromArray(int args[], int size) {
    List list = CursorAlloc();
    Position p = list;
    for (int i = 0; i < size; i++) {
        Insert(args[i], list, p);
        p = CursorSpace[p].Next;
    }
    CursorSpace[p].Next = 0;
    return list;
}

void
PrintCursorList(List l) {
    printf("[ ");
    Position p = CursorSpace[l].Next;
    while(p) {
        printf("%d ", CursorSpace[p].Element);
        p = CursorSpace[p].Next;
    }
    printf("]\n");
}
