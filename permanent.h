#ifndef _PERMANENT_H_
#define _PERMANENT_H_


/** Compute the permanent of a square matrix.
 *
 *  @param      x   Pointer to \c n times \c n doubles defining matrix \c x.
 *                  Can be stored in row-major or column-major order.
 *
 *  @param      n   Number of rows and columns in matrix \c x.
 *
 *  @returns    Permanent of matrix \c x.
 *
 */ double permanent(const double *x, const int n);


#endif
