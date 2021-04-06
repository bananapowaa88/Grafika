#include "matrix.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
    float identity[3][3];
    float scalar = 5;
	float multiMatr[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    printf("\na matrix:\n");
    print_matrix(a);
    printf("\nb matrix:\n");
    print_matrix(b);
    
    add_matrices(a, b, c);

    printf("\nc matrix:\n");
    print_matrix(c);

    identityMartix(identity);

    printf("\nidentity matrix:\n");
    print_matrix(identity);

    scalarMatrix(a, scalar);

    printf("\nscalar a matrix:\n");
    print_matrix(a);

    multiply_matrices(a,b,multiMatr);
    printf("\nmultiMatr matrix:\n");
    print_matrix(multiMatr);
	
    return 0;
}