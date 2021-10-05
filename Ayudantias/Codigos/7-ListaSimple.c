#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;//Datos de interes
	struct Node * next; //Para apuntar al nodo siguiente
}Nodo;

//Prototipos de funciones
void push(Nodo ** head_ref, int new_data);		//Agrega un nodo a la lista
void delete_node(Nodo **head_ref, int position);//Elimina el nodo en la posicion dada
void delete_list(Nodo ** head_ref);             //Elimina la lista completa
bool search(Nodo * head_ref, int x);			//Busca el dato x en cada nodo de la lista
void print_list(Nodo * node);					//Imprime los valores de la lista

int main(void)
{
	Nodo * head = NULL; //Nodo inicial
	int i;
	for (i = 0; i < 10; ++i)
	{
		push(&head, i);//Agregamos nodos con valor desde 0 hasta 9
	}
	print_list(head); //Imprimimos los valores en la lista
	delete_node(&head, 5); //Eliminamos el nodo en la posicion 5
	printf("Se elimina el nodo en la posición 5.\n");
	print_list(head); //Imprimimos nuevamente la lista

	//Buscamos el valor en la lista
	int to_search = 9;
	if (search(head, to_search)) printf("Se ha encontrado el valor %d.\n", to_search);
	else printf("No se ha encontrado el valor %d.\n", to_search);
	/*FREE*/
	delete_list(&head);//Eliminamos todos los nodos de la lista

	return 0;
}


/*-----------------IMPLEMENTACION FUNCIONES------------------*/

void push(Nodo ** head_ref, int new_data){
	Nodo * new_node = (Nodo *) malloc(sizeof(Nodo)); //Crea nodo 
	new_node->data = new_data;  //Asignamos el dato nuevo
	new_node->next = *head_ref; //El nodo nuevo apunta a la cabeza anterior
	*head_ref = new_node;       //Ahora la cabeza es el nodo nuevo
}

void delete_list(Nodo ** head_ref){
	Nodo * current = * head_ref;//Comenzamos con el nodo cabeza
	Nodo * next;//Declaramos un nodo siguiente al cual movernos

	while (current != NULL){//Mientras el nodo actual sea distinto de NULL
		next = current->next; //Asignamos el nodo siguiente
		free(current);  //Liberamos el actual
		current = next; //Movemos el actual al siguiente
	}
}

void delete_node(Nodo **head_ref, int position)
{
	if (*head_ref == NULL) return; //Si la cabeza es NULL terminamos con la funcion

	Nodo * temp = *head_ref;//Declaramos un nodo temporal

	if (position == 0)//Si la posicion es 0 (eliminar nodo cabeza)
	{
	    *head_ref = temp->next;//La cabeza pasa al siguiente   
	    free(temp);//Liberamos la memoria de la cabeza actual
	    return;
	}

	int i;
	for (i=0; temp!=NULL && i<position-1; i++) temp = temp->next; //Mientras el nodo sea distinto de NULL seguimos recorriendo hasta llegar a la posicion 

	if (temp == NULL || temp->next == NULL) return;//Caso final de lla lista
	Nodo *next = temp->next->next;//El proximo nodo será 2 nodos por delante del actual

	free(temp->next);//Liberamos el nodo siguiente al actual

	temp->next = next;//Reasignamos el nodo siguiente al actual
}

bool search(Nodo * head_ref, int x){
	Nodo* current = head_ref;
    while (current != NULL)
    {
        if (current->data == x) return true;
        current = current->next;
    }
    return false;
}

void print_list(Nodo * nodito){
	while (nodito != NULL){
		printf(" %d \n", nodito->data);
		nodito = nodito->next;
	}
}


/*REFERENCIAS

https://www.geeksforgeeks.org/data-structures/linked-list/singly-linked-list/
*/