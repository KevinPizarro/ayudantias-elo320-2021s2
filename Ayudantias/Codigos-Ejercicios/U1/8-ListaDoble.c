#include<stdio.h>
#include<stdlib.h>

typedef struct  Node{
   int data;
   struct Node *next;
   struct Node *prev;
}Nodo;

//Prototipos de funciones
void push(Nodo **head_ref, int new_data);//agrega nodo al comienzo de la lista
void print_list(Nodo *list); // Imprime la lista (LIFO)
void print_reverse(Nodo * list); // Imprime la lista al revés (FIFO)
void delete_node(Nodo** head_ref, Nodo* del); //Elimina el nodo dado


void main(void){
  Nodo *list = NULL;//Nodo inicial
  int i;

  //Añadimos nodos con valores desde 0 al 9
  for (i = 0 ; i < 10; i++){
    push(&list,i);
    printf("Se ha añadido el nodo con el valor %d.\n", i);
  } 

  print_list(list);
  print_reverse(list);

  delete_node(&list, list->next->next->next);
  printf("Se ha eliminado el 4to nodo.\n");

  print_list(list);
  print_reverse(list);
  
}


/*-----------------IMPLEMENTACION FUNCIONES------------------*/

void push(Nodo **head_ref, int new_data){
  Nodo *new_node = (Nodo *) malloc(sizeof(Nodo));//Creamos el nodo nuevo
  new_node->data = new_data; //Asignamos el valor de nuevo dato
  new_node->next = *head_ref;//El nodo nuevo (next) apunta a la cabeza anterior
  new_node->prev = NULL;     //El nodo nuevo (prev) apunta a NULL
  if(*head_ref != NULL) (*head_ref)->prev = new_node;//Si la cabeza anterior es distinta de NULL entonces ahora su prev apunta al nodo nuevo
  *head_ref = new_node;//La cabeza pasa a ser el nuevo nodo
}

void print_list(Nodo *list){
  printf("Imprimiendo la lista.\n");
  while(list != NULL){//Mientras el puntero no esa NULL entonces avanzamos al siguiente mientras imprimimos los valores
   printf("%d\n", list->data);
   list = list->next;
  }
}

void print_reverse(Nodo * list){
  printf("Imprimiendo la lista al revés.\n");
  if(list != NULL){
    while(list->next != NULL) list = list->next; //Mientras el nodo siguiente no sea NULL seguimos avanzando
    while(list != NULL){//Empezamos a retroceder imprimendo los valores mientras no sea NULL
       printf("%d\n", list->data);
       list = list->prev;
    }
  }
}

void delete_node(Nodo** head_ref, Nodo* del){
    if (*head_ref == NULL || del == NULL) return;//Si alguno de los dos es NULL
    if (*head_ref == del) *head_ref = del->next; // Si corresponde a la cabeza
 
    if (del->next != NULL) del->next->prev = del->prev; // Si no es el ultimo entonces el nodo siguiente al que sera eliminado ... 
    if (del->prev != NULL) del->prev->next = del->next; // Si no es el primero entonces el nodo previo al que sera eliminado ...
 
    free(del);//Se libera la memoria
    return;
}

/*REFERENCIAS
https://www.geeksforgeeks.org/data-structures/linked-list/#doublyLinkedList
*/