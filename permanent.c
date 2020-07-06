#include <math.h>

#include <cblas.h>


double permanent(const double *x, const int n) {

    // Permanent of a zero-by-zero matrix is one.
    if (!n)
        return 1.;

    // Allocate and fill Gray code from 0 to 'n'.
    int i, gray[n];
    for (i = 0; i != n; ++i)
        gray[i] = i;

    // Allocate delta array (all +1 to start).
    double delta[n];
    for (i = 0; i != n; ++i)
        delta[i] = 1.;

    // Allocate matrix for result of 'dgemv()'.
    double vec[n + 1];
    double *vec_end = vec + n;

    // Handle first Gray code.
    double result = 1., *vec_it;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, n, n, 1., x, n, delta, 1, 0., vec, 1);
    for (vec_it = vec; vec_it != vec_end; ++vec_it)
        result *= *vec_it;

    // Iterate over second to last Gray codes.
    int bound = n - 1, pos = 0, sign = 1;
    double prod;
    while (pos != bound) {
        // Update sign and delta.
        sign *= -1;
        *(delta + bound - pos) *= -1;
        // Compute each Gray code term.
        cblas_dgemv(CblasRowMajor, CblasNoTrans, n, n, 1., x, n, delta, 1, 0., vec, 1);
        prod = 1.;
        for (vec_it = vec; vec_it != vec_end; ++vec_it)
            prod *= *vec_it;
        result += sign * prod;
        // Go to next Gray code.
        *gray = 0;
        *(gray + pos) = *(gray + pos + 1);
        ++pos;
        *(gray + pos) = pos;
        pos = *gray;
    }

    // Divide by external factor and return permanent of 'x'.
    return result / exp2((double)bound);
};
