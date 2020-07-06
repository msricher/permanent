#include <stdio.h>

#include "permanent.h"


int main(void) {

    double matrix[64] = {
         1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.,  9., 10., 11., 12., 13., 14., 15., 16.,
        17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32.,
        33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48.,
        49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60., 61., 62., 63., 64.,
    };

    double correct[9] = {
        1., 1., 10., 450., 55456., 14480700., 6878394720., 5373548250000., 6427291156586496.,
    };

    double tests[9];

    printf("TESTING MATRIX { 1, ..., N } WITH SHAPE N-BY-N\n");

    int i;
    for (i = 0; i != 9; ++i) {
        tests[i] = permanent(matrix, i);
        printf(">> N: %1d\t\tCORRECT: %18.1f\tOUR VALUE: %18.1f\n", i, correct[i], tests[i]);
        if (correct[i] != tests[i]) {
            printf("FAILED TEST %1d\n", i);
            return 1;
        }
    }

    printf("PASSED ALL TESTS\n");
    return 0;
}
