#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(float a[3][3],float b[3][3], float c[3][3]);

/**
 * Inicialize a identity matrix 
 **/
void identityMartix(float matrix[3][3]);
/**
 * Scalar multiply a matrix wih a number
 **/
void scalarMatrix(float matrix[3][3], float num);

/**
 * Multiply two matrices 
 **/
void multiply_matrices(float a[3][3], float b[3][3],  float multiMatr[3][3]);

#endif // MATRIX_H

