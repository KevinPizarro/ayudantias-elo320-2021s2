
#include <stdio.h>
#include <stdlib.h>

typedef struct moldenodo{
  int clave;
  struct moldenodo *right;
  struct moldenodo *left;
}nodo;

nodo * new_node(int new_key);
nodo * insert(nodo * node, int new_key);
void print_inorder(nodo * node);
int count_nodes(nodo * node);
int mediana(nodo * node);
int buscar_por_indice(nodo * node, int index);

static int CONTADOR = 0;

int main(int argc, char const *argv[])
{
  nodo * root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Hay %d nodos dentro del árbol.\n", count_nodes(root));//7
  printf("La mediana del árbol es: %d.\n", mediana(root));//50
  return 0;
}

nodo * new_node(int new_key){
  nodo * temp = (nodo *) malloc(sizeof(nodo));
  temp->clave = new_key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

nodo * insert(nodo * node, int new_key){
  if (node == NULL) return new_node(new_key); //arbol vacío

  if (new_key < node->clave) node->left = insert(node->left, new_key); // llave menor que la llave del nodo actual -> me voy a la rama izquierda
  else if (new_key > node->clave) node->right = insert(node->right, new_key); // llave mayor que la llave del nodo actual -> me voy a la rama derecha

  return node;//Regresa el ptr al tope del arbol
}

void print_inorder(nodo * node){
  if (node != NULL) {
    print_inorder(node->left);//Entra recursivamente en la rama izquierda, luego pasa a la derecha printeando cuando corresponde
    printf("%d \n", node->clave);
    print_inorder(node->right);
  }
}



/*PREGUNTA 1: Diseñe una función recursiva que cuente el número total de nodos que tiene un árbol binario.*/

int count_nodes(nodo * node){
  int r_counter=0, l_counter=0, counter=0;
  if (node != NULL) {
    l_counter = count_nodes(node->left);
    r_counter = count_nodes(node->right);
    counter = l_counter + r_counter + 1;
  }
  else return 0;
  return counter;
}

/*PREGUNTA 3: Diseñe una función en C que calcule la mediana de números enteros almacenados en árbol
binario de búsqueda definido como en el problema 1. En el caso de que el número de elementos es par,
considere la media como el último elemento de la primera mitad.*/

int mediana(nodo * node){
  if (node == NULL) return -1;

  int n_nodos = count_nodes(node);
  int indice = 0;
  
  if (n_nodos % 2 == 0) indice = n_nodos/2 + 1; //n_nodos es par
  else indice = n_nodos/2; //n_nodos es impar
  //printf("El índice es: %d.\n", indice);
  int result = buscar_por_indice(node, indice);
  return result;
}

int buscar_por_indice(nodo * node, int index){
  int result = 0;
  if (node != NULL && CONTADOR != index) {
    buscar_por_indice(node->left, index);
    CONTADOR ++;
    if (CONTADOR == index+1) result = node->clave; 
    buscar_por_indice(node->right, index);
  }
  else return 0;
  return result;
}



/*PREGUNTA2: 
Diseñe un buffer circular, usando listas, para almacenar números enteros:
a) Haga un diagrama de su diseño. ¿Va a usar listas dobles o simplemente enlazadas? Especifique los punteros que necesita para manipular el buffer.
b) Defina, en C, el tipo del nodo del buffer.
c) Diseñe una función en C que agrege un nodo al buffer. Use el siguiente prototipo para la función: void agrega(nodo **, int );*/
/*

//CÓDIGO INCOMPLETO Y CON ERRORES
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct  Node{
   int data;
   struct Node *next;
   struct Node *prev;
}Nodo;

typedef struct Queue{
  Nodo * head;
  Nodo * tail;
  int size;
}Queue;

Queue * create_queue();
Nodo * new_node(int new_data);
void agrega(Nodo **tail, int new_data);
void print_list(Nodo *head);

void main(void){
  Queue* q = create_queue();
  int i = 0;
  for (i = 0; i < MAXSIZE; ++i)
    agrega(q, i);

}

*/
/*-----------------IMPLEMENTACION FUNCIONES------------------*/
/*
Queue * create_queue(){
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;//Cabeza y cola del buffer empiezan en NULL
    return q;
}

Nodo * new_node(int new_data){
    Nodo * temp = (Nodo *) malloc(sizeof(Nodo));
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}

void agrega(Nodo * q, int new_data){
    Nodo* temp = new_node(new_data);//Nuevo nodo a añadir
    
    if (q->tail == NULL) {//Si está vacio el buffer...
        q->tail = temp;//Nuevo nodo será asignado a la cabeza y la cola
        return;
    }
    //Si ya había elementos en el buffer entonces...
    q->tail->next = temp;//La cola es actualizada, apunta al nuevo nodo
    q->tail = temp;//La cola toma como valor el nuevo nodo
}

void print_list(Nodo *head){
  printf("Imprimiendo la lista.\n");
  while(head != NULL){//Mientras el puntero no esa NULL entonces avanzamos al siguiente mientras imprimimos los valores
   printf("%d\n", head->data);
   head = head->next;
  }
}
*/