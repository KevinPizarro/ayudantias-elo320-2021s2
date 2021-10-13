//Implementacion Werner

#include <stdio.h>
#include <stdlib.h>

typedef int item;
static item * q; //Equivalente a static int *q;
static int N, cabeza, cola, encolados; //N= tamaño max de buffer, cabeza y cola para llevar registro de dónde se está apuntando, encolados para el largo actual del buffer

//Inicialización del buffer
void QueueInit(int MAXN){
    q = malloc((MAXN)*sizeof(item));
    N = MAXN+1 ; cabeza = 0; encolados = 0; cola = 0;
}

//Saca/consume/eliminta un elemento. Avanza el "puntero" a la cabeza en 1
item QueueGet(){
    item consumido = q[cabeza];
    cabeza = (cabeza + 1) % N;
    encolados--;
    return(consumido); 
}

//Revisa si el buffer está lleno
int QueueFull(){
    return(encolados == N);
}

//Revisa si el buffer está vacío
int QueueEmpty(){
    return(encolados == 0);
}

//Pone/añade elemento al buffer. Avanza el "puntero" a la cola en 1
void QueuePut(item a){
    if(!QueueFull()){
        q[cola] = a;
        cola = (cola + 1) % N;
        encolados++;
    }
}

//Libera el espacio solicitado por el buffer
void QueueDelete(){
    free(q);
}

//Imprime los valores válidos dentro del buffer. Revisar funcionamiento cuando buffer está lleno.
void imprime(){
    int cursor;
    for(cursor = cabeza; cursor < cola; cursor++)
        printf("%d\n", q[cursor]);  
}

void main(void){
    item i;
    QueueInit(17);
    for( i = 0; i<10; i++)//Qué pasa si se añaden más elementos que 17?
        QueuePut(i);
    imprime();
    printf("Cola: %d,  Cabeza: %d\n ", cola, cabeza);
    printf("\n%d\n\n", QueueGet());
    imprime();
    printf("Cola: %d,  Cabeza: %d\n", cola, cabeza);
    QueuePut(978);
    printf("\n");
    imprime();
    printf("Cola: %d, Cabeza: %d\n", cola, cabeza); 
}



/*
#include <stdio.h>
#include <stdlib.h>
 
//Implementacion con Lista simplemente enlazada
typedef struct Nodo {
    int data;
    struct Nodo* next;
}Nodo;
 

//Una fila tendrá punteros a los nodos de la cabeza y la cola
typedef struct Queue {
    struct Nodo *head, *tail;
}Queue;
//También se puede definir un MAXSIZE Queue, para que tenga el mismo comportamiento


Nodo * new_node(int new_data);//Crea un nuevo nodo
Queue* create_queue(); //Crea el buffer
void enqueue(Queue * q, int new_data);//Añade elemento al buffer
void dequeue(Queue * q);//Quita elemento al buffer

int main()
{
    Queue* q = create_queue();
    enqueue(q, 10);//añade valor 10
    enqueue(q, 20);//añade valor 20
    dequeue(q);//quita el de valor 10
    enqueue(q, 30);//añade valor 30
    enqueue(q, 40);//añade valor 40
    enqueue(q, 50);//añade valor 50
    dequeue(q);//quita el de valor 20
    printf("Queue head: %d \n", q->head->data);//Head queda en 30
    printf("Queue tail: %d \n", q->tail->data);//Tail queda en 50
    return 0;
}

Nodo * new_node(int new_data){
    Nodo * temp = (Nodo *) malloc(sizeof(Nodo));
    temp->data = new_data;
    temp->next = NULL;
    return temp;
}
 
Queue * create_queue(){
    Queue * q = (Queue*)malloc(sizeof(Queue));
    q->head = q->tail = NULL;//Cabeza y cola del buffer empiezan en NULL
    return q;
}

void enqueue(Queue * q, int new_data)
{
    Nodo* temp = new_node(new_data);//Nuevo nodo a añadir
    
    if (q->tail == NULL) {//Si está vacio el buffer...
        q->head = q->tail = temp;//Nuevo nodo será asignado a la cabeza y la cola
        return;
    }
    //Si ya había elementos en el buffer entonces...
    q->tail->next = temp;//La cola es actualizada, apunta al nuevo nodo
    q->tail = temp;//La cola toma como valor el nuevo nodo
}
 
void dequeue(Queue * q)
{
    if (q->head == NULL) return;//Si el buffer está vacio no hay nada que hacer
 
    Nodo* temp = q->head;//Variable temporal que es igual a la cabeza
 
    q->head = q->head->next;//Cabeza apunta al siguiente elemento
 
    if (q->head == NULL) q->tail = NULL;//Si al modificar llegue a NULL implica que quedó vacío
 
    free(temp);//Libera memoria
}
*/

/* REFERENCIA
https://www.geeksforgeeks.org/circular-queue-set-2-circular-linked-list-implementation/
*/