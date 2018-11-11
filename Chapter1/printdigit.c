#include <stdio.h>
void PrintDigit(unsigned int N) {
    printf("%d", N);
}

void PrintOut(int N) {
    if (N < 0) {
        printf("-");
        N = -N;
    }
    if (N >= 10 || N <= -10) {
      PrintOut(N / 10);
    }
    PrintDigit(N % 10);
}

