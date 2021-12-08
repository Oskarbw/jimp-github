#include "../src/gauss.h"
#include <assert.h>

int main(int *argc, char **argv) {
    Matrix matrix;
    matrix.r = 1;
    matrix.c = 1;
    eliminate(&matrix, &matrix);
    assert(1 == 2);
    return 0;
}
