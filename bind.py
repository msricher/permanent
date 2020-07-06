from os import path
from ctypes import c_int, c_double

from numpy.ctypeslib import load_library, ndpointer


__all__ = [
    'permanent',
    ]


_permanent = load_library('permanent', path.dirname(__file__)).permanent
_permanent.argtypes = ndpointer(c_double, ndim=2, flags='CONTIGUOUS'), c_int
_permanent.restype = c_double


def permanent(matrix):
    r"""
    Compute the permanent of a square matrix with Glynn's algorithm.

    Matrix must be C- or F- contiguous.

    Parameters
    ----------
    matrix : numpy.ndarray
        Square matrix with dtype=double, ndim=2, shape[0] == shape[1].

    Returns
    -------
    permanent : float
        Permanent of the matrix.

    """
    if matrix.shape[0] != matrix.shape[1]:
        raise ValueError('matrix is not square')
    elif matrix.flags['F_CONTIGUOUS']:
        matrix = matrix.transpose()
    return _permanent(matrix, matrix.shape[0])
