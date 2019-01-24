#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "BinarySortTree.h"

// 如果不想在其他c文件中使用该数据结构，就把结构体定义在c文件中。
// struct TreeNode
// {
//     int Element;
//     SearchTree Left;
//     SearchTree Right;
// };

SearchTree
MakeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position
Find(int X, SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    if (X < T->Element) {
        return Find(X, T->Left);
    } else if (X > T->Element) {
        return Find(X, T->Right);
    } else {
        return T;
    }
}

Position
FindMin(SearchTree T) {
    if (T == NULL) {
        return NULL;
    } else if (T->Left == NULL) {
        return T;
    } else {
        return FindMin(T->Left);
    }
}

Position
FindMax(SearchTree T) {
    if (T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    return T;
}


SearchTree
Insert(int X, SearchTree T) {
    if(T == NULL) {
        /* Create and return a one-node tree */
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL) {
            fprintf(stderr, "malloc TreeNode fail!");
            exit(1);
        } else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } else if(X < T->Element) {
        T->Left = Insert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
    }
    /* Else X is in the tree already; we'll do nothing */
    return T;
}

SearchTree
Delete(int X, SearchTree T) {
    Position TmpCell;
    if (T == NULL) {
        fprintf(stderr, "Element not found");
    } else if (X < T->Element) {
        /* Go left */
        T->Left = Delete(X, T->Left);
    } else if (X > T->Element){
        /* Go Right */
        T->Right = Delete(X, T->Right);
    } else if (T->Left && T->Right){
        /* Found element to be deleted */
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(X, T->Right);
    } else {
        /* One or zero childre */
        TmpCell = T;
        if (T->Left == NULL) {
            /* Also handles 0 children*/
            T = T->Right;
        } else if (T->Right == NULL) {
            T = T->Left;
        }
        free(TmpCell);
    }
    return T;
}


// int main(int argc, char const *argv[])
// {
//     int arr[] = {2,3,6,4,5,8,7,9,10,1};
//     SearchTree T = MakeEmpty(NULL);
//     for (size_t i = 0; i < 10; i++)
//     {
//         T = Insert(arr[i], T);
//     }
//     Position min = FindMin(T);
//     Position max = FindMax(T);
//     Position find_3 = Find(3, T);
//     SearchTree del3 = Delete(3, T);
//     Position del_find_3 = Find(3, del3);
//     printf("min in Tree: %d\n", min->Element);
//     printf("max in Tree: %d\n", max->Element);
//     printf("3 in Tree T ? ");
//     if (find_3 != NULL) {
//         printf("yes\n");
//     } else {
//         printf("no\n");
//     }
//     printf("Is 3 del? ");
//     if (del_find_3 != NULL) {
//         printf("no\n");
//     } else {
//         printf("yes\n");
//     }
//     return 0;
// }
