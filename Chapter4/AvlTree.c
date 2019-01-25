#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"

struct AvlNode {
    int Element;
    AvlTree Right;
    AvlTree Left;
    int Height;
};

static int
Height(Position P) {
    if (P == NULL) {
        return -1;
    } else {
        return P->Height;
    }
}

static int
Max(int a, int b) {
    return a > b ? a : b;
}


/** This function can be called by only if K2 has a left child */
/** Perform a rotate between a node (K2) and its left child  */
/** Update heights, then return new root */
/** LL situation */
static Position 
SingleRotateWithLeft(Position K2) {
    Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;

    /** new root */
    return K1;
}


/** RR situation */
static Position
SingleRotateWithRight(Position K2) {
    Position K1;

    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->Height = Max(Height(K2->Right), Height(K2->Left)) + 1;
    K1->Height = Max(Height(K1->Right), K1->Height) + 1;

    /** new root */
    return K1;
}


/** This function can be called only if K3 has a left */
/** child and K3's left child has a right child  */
/** Do the left-right double rotation */
/** Update heights, then return new root */
/** LR situation */
static Position
DoubleRotateWithLeft(Position K3) {
    /** Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight(K3->Left);

    /** Rotate between K2 and K3 */
    return SingleRotateWithLeft(K3);
}


/** RL situation */
static Position
DoubleRotateWithRight(Position K3) {
    /** Rotate between K1 and K2 */
    K3->Right = SingleRotateWithLeft(K3->Right);

    /** Rotate between K2 and K3 */
    return SingleRotateWithRight(K3);
}


AvlTree
Insert(int X, AvlTree T) {
    if (T == NULL) {
        /* Create and return a one-node tree Create and return a one-node tree  */
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL) {
            fprintf(stderr, "Out of space!!!");
        } else {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    } else if (X < T->Element){
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            /** LL situation */
            if (X < T->Left->Element) {
                T = SingleRotateWithLeft(T);
            } else {
            /** LR situation */
                T = DoubleRotateWithLeft(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X > T->Right->Element) {
            /** RR situation */
                T = SingleRotateWithRight(T);
            } else {
            /** RL situation */
                T = DoubleRotateWithRight(T);
            }
        }
    }

    /** Else X in the tree already; we'll do nothing   */
    T->Height = Max(Height(T->Right), Height(T->Left)) + 1;
    return T;
}


Position
Find(int X, AvlTree T) {
    if (T == NULL) {
        return NULL;
    } 
    if (X > T->Element) {
        return Find(X, T->Right);
    } else if (X < T->Element) {
        return Find(X, T->Left);
    } else {
        return T;
    }
}

Position
FindMin(AvlTree T) {
    if (T == NULL) {
        return NULL;
    } else if (T->Left == NULL) {
        return T;
    } else {
        return FindMin(T->Left);
    }
}

AvlTree
Delete(int X, AvlTree T) {
    Position TmpCell;

    if (T == NULL) {
        fprintf(stderr, "Element not found");
    } else if (X < T->Element) {
        T->Left = Delete(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Delete(X, T->Right);
    } else if (T->Left && T->Right) { /* Two children */
        /** Found element to be deleted */
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    } else {
        /** One or zero children */
        TmpCell = T;
        if (T->Left == NULL) {
            /** Also handles 0 children */
            T = T->Right;
        } else if (T->Right == NULL) {
            T = T->Left;
        } else {
            free(TmpCell);
        }
    }
    return T;
}


Position
FindMax(AvlTree T) {
    if (T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}

AvlTree
MakeEmpty(AvlTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}


int main(int argc, char **argv) {
    int arr[] = {2,3,6,4,5,8,7,9,10,1,11,12,13,14,15,16,17};
    AvlTree T = MakeEmpty(T);
    for(size_t i = 0; i < 17; i++) {
        T = Insert(arr[i], T);
    }
    Position min = FindMin(T);
    Position max = FindMax(T);
    Position find_3 = Find(3, T);
    AvlTree del3 = Delete(3, T);
    Position del_find_3 = Find(3, del3);
    printf("min in Tree: %d\n", min->Element);
    printf("max in Tree: %d\n", max->Element);
    printf("3 in Tree T ? ");
    if (find_3 != NULL) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    printf("Is 3 del? ");
    if (del_find_3 != NULL) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    return 0;
}
