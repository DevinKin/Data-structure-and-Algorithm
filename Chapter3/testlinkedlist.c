#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    List list = MakeEmpty();
    if (IsEmpty(list)) {
        printf("empty list\n");
    } else {
        printf("not empty list\n");
    }
    int arr[] = {1,2,3,4,5};
    fromArray(list, arr, 5);
    printLinkedList(list);

    Position p = Find(8, list);
    if (p != NULL) {
        printf("8 in list\n");
    } else {
        printf("8 not in list\n");
    }
}
