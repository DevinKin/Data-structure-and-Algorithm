#include <stdlib.h>
#include <stdio.h>
#include "prime.h"
#include "myerror.h"
#include "HshSep.h"

#define MinTableSize    10


struct ListNode {
    int Element;
    Position next;
};


/** List *TheLists will be an array of lists, allocated later */
/** The lists use headers (for simplicity),  */
/** though this wastes space */
struct HashTb1 {
    int TableSize;
    List *TheLists;
};


HashTable
InitializeTable(int TableSize) {
    HashTable H;
    int i;

    if (TableSize < MinTableSize) {
        FatalError("InitializeTable", "Table size too small");
        return NULL;
    }

    /** Allocate table */
    H = malloc(sizeof(struct HashTb1));
    if (H == NULL) {
        FatalError("InitializeTable", "Out of space!!!");
        exit(1);
    }

    H->TableSize = nextPrime(TableSize);
    
    /** ALlocate array of lists */
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) {
        FatalError("InitializeTable", "Out of space!!!");
        exit(1);
    }

    /** Allocate list headers */
    for(i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL) {
            FatalError("InitializeTable", "Out of space!!!");
            exit(1);
        } else {
            H->TheLists[i]->next = NULL;
        }
    }

    return H;
}

static int
Hash(int key, int TableSize) {
    return key % TableSize;
}


Position
Find(int Key, HashTable H) {
    Position P;
    List L;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->next;

    while (P != NULL && P->Element != Key) {
        P = P->next;
    }

    return P;
}


void 
Insert(int Key, HashTable H) {
    Position Pos, NewCell;
    List L;
    
    Pos = Find(Key, H);

    if (Pos == NULL) {
        // Key is not found
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL) {
            FatalError("Insert", "Out of space!!!");
            exit(1);
        } else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->next = L->next;
            NewCell->Element = Key;
            L->next = NewCell;
        }
    } 
}

int
Retrieve(Position P) {
    if (P != NULL) {
        return P->Element;
    } else {
        return -1;
    }
}


void DestoryList(List L) {
    List TmpCell = L;

    while (TmpCell != NULL) {
        TmpCell = L->next;
        free(L);
        L = TmpCell;
    }
}


void DestoryTable(HashTable H) {
    for (int i = 0; i < H->TableSize; i++) {
        DestoryList(H->TheLists[i]);
    }
    free(H);
}



int main() {
    HashTable H = InitializeTable(20);

    for (int i = 0; i < 200; i++) {
        Insert(i + 1, H);
    }

    /** List L = H->TheLists[2]; */
    List L;
    /** printf("List[2]: "); */

    for (int i = 0; i < H->TableSize; i++) {
        printf("List[%d]: ", i);
        L = H->TheLists[i];
        while (L != NULL) {
            L = L->next;
            printf(" %d", Retrieve(L));
        }
        printf("\n");
    }

    Position p = Find(118, H);

    printf("%d in HashTable\n", Retrieve(p));
    
    printf("H->Size: %d\n", H->TableSize);

    printf("%d next is: %d\n", Retrieve(p), Retrieve(p->next));

    DestoryTable(H);
}
