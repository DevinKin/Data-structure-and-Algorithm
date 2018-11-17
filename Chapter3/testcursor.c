#include "cursor.h"
#include <stdio.h>

extern struct Node CursorSpace[];

int main(void) {
    int arr[] = {1,2,3,4,5};
    InitializeCursorSpace();
    List L = FromArray(arr, 5);
    PrintCursorList(L);
    Position p = FindPrevious(3, L);
    printf("CursorSpace[%d]=%d\n", CursorSpace[p].Element, p);
}
