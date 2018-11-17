#include "stackwitharray.h"
#include <stdio.h>

int main(void) {
    int N = 10;
    Stack S = CreateStack(N);
    printf("Stack is empty? %d\n", IsEmpty(S));

    for (int i = 0; i < N; i++) {
        Push(i, S);
        printf("%d push in stack\n", S->Array[S->TopOfStack]);
    }

    printf("Element in Stack:\n");
    while (!IsEmpty(S)) {
        printf("%d ", TopAndPop(S));
    }

    DisposeStack(S);
}
