#include "matrix.h"

#include <stdio.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
	int i;
	int j;
	
	for(i=0; i<3; ++i){
		for(j=0; j<3; ++j){
			
		}
	}
}

void print_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void add_matrices(float a[3][3],float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void identityMartix(float matrix[3][3]){
    int i;
    int j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            } else{
                matrix[i][j] = 0;
            }   
        }   
    }
}

void scalarMatrix(float matrix[3][3], float num){
    int i;
    int j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            matrix[i][j] *= num; 
        }
    }
}

void multiply_matrices(float a[3][3], float b[3][3], float multiMatr[3][3]){
    float tmp;
    int i;
    int j;
    int k;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tmp = 0;
            for (k = 0; k < 3; ++k)
            {
                tmp = tmp + a[i][k] * b[k][j];
            }

            multiMatr[i][j] = tmp;
        }
    }
}