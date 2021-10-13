//IMPLEMENTACION Werner

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct{
	int size;//tamaño actual. size = 0 implica stack vacío size = MAXSIZE implica que esta lleno
	int items[MAXSIZE];//Arreglo de tamaño MAXSIZE
}STACK;

//Añade elemento al stack
void push(STACK *ps, int x){
	if (ps->size == MAXSIZE)
	{
		fputs("Error: stack overflow\n", stderr);
		abort();
	}
	else{
		ps->items[ps->size ++] = x;//Ojo con la notación. Primero asigna el valor en el espacio vacío, luego actualizar el valor de ps->size
	}
}

//Consume/elimina elemento del stack
int pop(STACK *ps){
	if (ps->size == 0){
		fputs("Error: Stack underflow\n", stderr);
		abort();
	}
	else
		ps->items[-- ps->size];
}

//Inicializa el stack 
void StackInit(STACK *ps){
	ps->size = 0;//Inicializa con tamaño actual 0
}

//Imprime todos los valores contenidos en el stack
void imprime(STACK *ps){
	int encabezado = ps->size - 1;
	for (encabezado; encabezado >= 0; encabezado--)
		printf("%d\n", ps->items[encabezado]);
}

void main(void)
{
	STACK * ps = (STACK *) malloc(sizeof(STACK));
	StackInit(ps);
	int i = 0;
	printf("Push.\n");
	for (i = 0; i <= 10; i++)
		push(ps, i);
	imprime(ps);
	printf("Pop.\n");
	for(i = 0; i <= 5; i++)
		pop(ps);
	imprime(ps);
}

/*
#include<stdio.h>
#include <stdlib.h>

//Implementación Lista simplemente enlazada
typedef struct Nodo{
	int data;
	struct Nodo * next;
}Nodo;
//Tambien se podría crear una variable que nos defina el tamaño máximo

void push(Nodo ** top, int new_data); //Añade elemento/nodo al stack
void pop(Nodo ** top); //Elimina elemento del stack
void print_all(Nodo * top); //Imprime todos los elementos en el stack
void lenght(Nodo * top);

int main(int argc, char const *argv[])
{
	Nodo * top = NULL;
	int i;
	for (i = 0; i <= 10; ++i)
	{
		push(&top, i);	
	}	

	lenght(top);
	print_all(top);

	for (i = 0; i < 5; ++i)
	{
		pop(&top);	
	}	

	lenght(top);
	print_all(top);
	return 0;
}

void push(Nodo ** top, int new_data){
	Nodo * nuevo_nodo;
	nuevo_nodo = (Nodo *) malloc(sizeof(Nodo));
	nuevo_nodo->data = new_data;

	if (*top == NULL) //No hay elementos en el stack
		nuevo_nodo->next = NULL;
	else//En otro caso, empujo los demás
		nuevo_nodo->next = *top;
	*top = nuevo_nodo;//Se convierte en el nuevo top del stack
}

void pop(Nodo ** top){
	if (*top == NULL)//No hay elementos que eliminar
		return;
	else{//Hay elementos en el stack
		Nodo * temp = *top;
		*top = temp->next;
		free(temp);
	}
}

void print_all(Nodo * top){
	if (top == NULL) return;
	else{
		Nodo * temp = top;
		while (temp != NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
}

void lenght(Nodo * top){
	if (top == NULL) printf("El stack está vacío.\n");
	else{
		int i;
		Nodo * temp = top;
		while (temp != NULL){
			i++;
			temp = temp->next;
		}
		printf("Hay %d elementos en el stack.\n", i);
	}
}
*/
/*Referencia
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
*/