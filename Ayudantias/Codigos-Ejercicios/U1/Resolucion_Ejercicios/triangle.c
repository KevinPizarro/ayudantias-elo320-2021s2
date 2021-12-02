#include "stdio.h"

int main(void)
{
	int filas, i, j;

	printf("Ingrese la cantidad de filas/altura del triángulo: ");
	scanf("%d", &filas);

	for (i = 0; i < filas; ++i)//Para pararse en una fila
	{
		for (j = 0; j <= i; ++j)//Para imprimir los * dependiendo de la fila
		{
			printf("* ");	
		}
		printf("\n");
	}
	return 0;
}

/*
Para poder imprimir una piramide se debe tener en cuenta que la cantidad de espacios a la izquierda debe ser menor cada fila. Por ejemplo una piramide de 
5 filas, en la fila 5 no tendra corrimiento, en la fila 4 se tendra 1 corrimiento, en la fila 3 ... y así.

Para poder imprimir un diamante se debe seguir una lógica similar, pero tomando en cuenta que estamos imprimiendo dos piramides, una de ellas esta invertida.
*/