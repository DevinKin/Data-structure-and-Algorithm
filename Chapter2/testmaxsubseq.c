#include <stdio.h>
#include "maxsubseq.h"

int main(void) {
    int A[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int alg1 = MaxSubsequenceSum1(A, sizeof(A) / sizeof(int));
    printf("alg1: %d\n", alg1);
    int alg2 = MaxSubsequenceSum2(A, sizeof(A) / sizeof(int));
    printf("alg2: %d\n", alg2);
    int alg3 = MaxSubsequenceSum3(A, 0, sizeof(A) / sizeof(int) - 1);
    printf("alg3: %d\n", alg3);
    int alg4 = MaxSubsequenceSum4(A, sizeof(A) / sizeof(int));
    printf("alg4: %d\n", alg4);
}
