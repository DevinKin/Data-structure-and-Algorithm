#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"

struct AvlNode {
    int Element;
    AvlTree Right;
    AvlTree Left;
    int Height;
};

static int
Height(Position P) {
    if (P == NULL) {
        return -1;
    } else {
        return P->Height;
    }
}

int main(int argc, char **argv) {

    return 0;
}
