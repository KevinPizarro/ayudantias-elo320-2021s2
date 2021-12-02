#include "stdio.h"
#define SIZE 2
int main(void)
{
	int matriz [SIZE][SIZE];
	int i,j, determinante;

	matriz[0][0] = 0;
	matriz[0][1] = 1;
	matriz[1][0] = 1;
	matriz[1][1] = 2; 


	for (i = 0; i < SIZE; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			printf("El valor en la posición (%d,%d) es: %d\n", i,j,matriz[i][j]);
		}
	}

	determinante = matriz[0][0]*matriz[1][1] - matriz[1][0]*matriz[0][1];

	printf("El determinante de la matriz es: %d\n", determinante);


	return 0;
}

/*
Para una matriz de 3x3 basta con implementar la regla de sarrus de manera analoga
*/