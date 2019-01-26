#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

#define true 1
#define false 0

static int
isPrime(size_t p) {
    int k;

    k = (int) sqrt((double) p);
    /** printf("k: %d\n", k); */

    for (size_t i = 2; i <= k; i++) {
        if (p % i == 0)
            return false;
    }

    return true;
}


int
nextPrime(size_t p) {
    if (p <= 2) return 2;

    while (!isPrime(p)) {
        p += 1;
    }

    return p;
}

/** int main() { */
    /** int t = 13; */
    /** printf("is 13 prime? %d\n", isPrime(13)); */
    /** printf("nextPrime %d\n", nextPrime(18)); */
/** } */
