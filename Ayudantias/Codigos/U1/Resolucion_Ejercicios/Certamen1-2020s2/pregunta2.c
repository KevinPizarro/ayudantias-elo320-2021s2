/*CODIGO INCOMPLETO Y CON ERRORES*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_buffer
{
	int data;
	struct nodo_buffer * prev;
	struct nodo_buffer * next;
}nBuffer;

void agrega(nBuffer **, int );


int main(int argc, char const *argv[])
{
	nBuffer * head = NULL, * tail = NULL;
	tail->next = NULL;
	agrega(&tail, 10);

	return 0;
}

void agrega(nBuffer ** tail_ref, int new_data){
	//Chequear tamaño.
	nBuffer * nuevo_nodo;
	if (*tail_ref == NULL){
		nuevo_nodo = (nBuffer *)malloc(sizeof(nBuffer));
		nuevo_nodo->prev = NULL;
		nuevo_nodo->next = NULL;
		nuevo_nodo->data = new_data;
		*tail_ref = (*tail_ref)->next;
	}
	else{
		nuevo_nodo->data = new_data;
		*tail_ref = nuevo_nodo;
		*tail_ref = (*tail_ref)->next;
	}
}

//pbm = portable bit map 0-1
//pgm = portable gray map 0-255