#include <stdio.h>
#include "stackwithlist.h"

int main(void) {
    Stack S = CreateStack();
    Push(1, S);
    int top = Top(S);
    printf("stack top: %d\n", top);
    Push(2, S);
    top = Top(S);
    printf("stack top: %d\n", top);
    Push(3, S);
    top = Top(S);
    top = Top(S);
    printf("stack top: %d\n", top);
    Pop(S);
    Pop(S);
    Pop(S);
    DisposeStack(S);
}
