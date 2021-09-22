#include <stdio.h>
#define SIZE 5

void print_array(int array[SIZE]);

//Arreglo: Estructura de datos que colecciona/agrupa en sectores de memoria contiguo elementos de un mismo tipo.
int main(){
	/*-----------ARREGLOS-----------*/
	/*
	printf("\n\n-----------ARREGLOS-----------\n\n");
	int numbers [SIZE] = {0,0,0,0,0}; //Declaración e inicialización del arreglo.
	print_array(numbers);
	numbers[2] = 66;
	printf("\nLuego del cambio\n");
	print_array(numbers);
*/

	//¿Y si printeamos fuera de los límites?
	//printf("Arreglo en índice -10 es %i\n", numbers[-10]);
	//printf("Arreglo en índice SIZE+1 es %i\n", numbers[SIZE+107]);


	/*-----------PUNTEROS-----------*/
	
	printf("\n\n-----------PUNTEROS-----------\n\n");
	int * ptr = NULL;
	printf("Dirección a la que apunta inicialmente ptr %p.\n", ptr);
	int numero = 1;
	ptr = &numero;
	
	printf("Valor de número %i.\n", numero);
	printf("Dirección a la que apunta ptr %p, con valor %i.\n", ptr,*ptr);
	*ptr = 4;
	printf("\nCAMBIO\n");
	printf("Valor de número %i.\n", numero);
	printf("Dirección a la que apunta ptr %p, con valor %i.\n", ptr,*ptr);
	numero = 88;
	printf("\nCAMBIO\n");
	printf("Valor de número %i.\n", numero);
	printf("Dirección a la que apunta ptr %p, con valor %i.\n", ptr,*ptr);
	
	//¿Y si cambiamos a dónde apunta ptr?
	ptr++;
	printf("Dirección a la que apunta ptr luego de sumarle '1' %p, con valor %i.\n", ptr, *ptr);

	return 0;	
}



void print_array(int array[SIZE]){
	int index = 0;
	int value = 0;
	printf("Tamaño de secciones %i bytes.\n", sizeof(array[index]));
	for(index=0; index < SIZE; index++){
		value = array[index];
		printf("La lectura del arreglo en el índice %i es: %i con dirección de memoria %p.\n", index, value, &array[index]);
	}
}

/* REFERENCIAS
Arreglos: https://www.geeksforgeeks.org/arrays-in-c-cpp/
Asignación de memoria: https://www.geeksforgeeks.org/difference-between-static-and-dynamic-memory-allocation-in-c/
Punteros: https://www.javatpoint.com/c-pointers
      	  https://www.tutorialspoint.com/cprogramming/c_pointers.htm
*/
