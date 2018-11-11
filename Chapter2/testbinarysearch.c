#include <stdio.h>
#include "binarySearch.h"

int main(void) {
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int len = sizeof(A) / sizeof(int);

    int pos =BinarySearch(A, 15, len);
    printf("%d position in A is: %d\n", 15, pos);
}
