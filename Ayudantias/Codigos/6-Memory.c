#include <stdio.h>
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	int numero = 5; //Esto es memoria estatica/stack

	//memoria dinamica/heap 
	int * p;
	p = (int *) malloc(sizeof(int)); //malloc o calloc sirven. calloc inicializa los valores en 0, malloc no
	if(p!=NULL) printf("La memoria dinámica ha sido asignada correctamente.\n");
	else printf("Hubo problemas en la asignación de memoria dinámica.\n");

	*p = 5;
	/*RESTO DEL PROGRAMA*/
 
	free(p); //Finalmente se debe liberar la memoria dinamica asignada, para prevenir las fugas de memoria
	return 0;
}

/* Corroborar fugas de memoria usando 
valgrind ./a.out
*/