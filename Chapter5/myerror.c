#include <stdio.h>
#include "myerror.h"


void
FatalError(char *func, char *msg) {
    fprintf(stderr, "func: %s, error: %s", func, msg);
}
