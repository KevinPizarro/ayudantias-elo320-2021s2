#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct persona
{
	struct persona * prev;
	struct persona * next;
	int edad;
	int dinero;
}persona;

//Prototipos Funciones
persona * crear_persona();
void ins_persona (persona ** primera, persona * nueva_persona);
void atendido(persona ** primera);
void imprimir(persona * primera);
void nuevos_datos(int * edad, int * um);
void identificar_mayores(persona * primera);
void insertar(persona ** fila, persona * colada, int posicion);

int contador_fila = 0;//Variable global



//Idea principal del programa. Se pueden afinar detalles o seguir arreglando posibles bugs.
int main(int argc, char const *argv[])
{
	time_t t;
    srand((unsigned) time(&t));
	persona * first = NULL;

	int llegan_personas, prob_colar, posicion;
    int i;

	while(1){
		imprimir(first);
		printf("----------------------------\nHay %d personas en la fila.\n----------------------------\n", contador_fila);
		identificar_mayores(first);
		srand((unsigned) time(&t));
		if (contador_fila > 0)
		{
			atendido(&first);
			contador_fila--;
		}
		llegan_personas=rand()%4;
		for (i = 0; i < llegan_personas; ++i)
		{
			ins_persona(&first, crear_persona());
			contador_fila++;
		}
		printf("----------------------------\nHan llegado %d personas a la fila.\n----------------------------\n",llegan_personas);
		sleep(5);
		prob_colar = rand()%101;
		if (prob_colar <= 25)//Probabilidad de colarse
		{
			posicion = (rand()%contador_fila)+1;
			insertar(&first, crear_persona(),posicion);
			printf("Se ha colado una persona entre las personas %d y %d.\n", posicion, posicion+1);
			contador_fila++;
		}
		
	}

	while(contador_fila > 0) atendido(&first);
	return 0;
}


/*-----------------IMPLEMENTACION FUNCIONES-------------------*/
persona * crear_persona(){
	int edad, um;
	nuevos_datos(&edad, &um);
	persona * personita = (persona *) malloc(sizeof(persona));
	personita->edad = edad;
	personita->dinero = um;
	return personita;
}

void ins_persona (persona ** primera, persona * nueva_persona){
	persona * ultimo = *primera;
	if(*primera == NULL){
		nueva_persona->prev = NULL;
		nueva_persona->next = NULL;
		*primera = nueva_persona;
		return;
	}

	while(ultimo->next != NULL) ultimo = ultimo->next;
	ultimo->next = nueva_persona;
	nueva_persona->prev = ultimo;
	nueva_persona->next = NULL;
}

void atendido(persona ** primera){
	if(*primera == NULL) return;
	persona * temp;
	if ((*primera)->next == NULL) free(*primera);	
	else{
		temp = *primera;
		*primera = (*primera)->next;
		(*primera)->prev = NULL;
		free(temp);
		printf("----------------------------\nLa primera persona ha sido atendida.\n----------------------------\n");
	}
}

void imprimir(persona * primera){
	if(primera == NULL) return;
	int i=1;
	persona * final;
	final = primera;
	while(final!=NULL){
		printf("Persona N°%d, de %d años y con %d unidades monetarias.\n", i, final->edad,final->dinero);
		final = final->next;
		i++;
	}
}

void nuevos_datos(int * edad, int * um){
	*edad = rand()%183+18;
	*um = rand()%233;
}

void identificar_mayores(persona * primera){
	if(primera == NULL) return;
	persona * current = primera;

	int counter = 0;
	while(current != NULL){
		if (current->edad >= 70) counter++;
		current = current->next;
	}
	if (counter == 0) printf("No hay personas mayores de 70 años en la fila.\n");
	else printf("Hay %d personas mayores de 70 años en la fila.\n", counter);
}

//Insertar luego de la posicion dada. Ej posicion 5, se coloca entre persona 5 y 6
void insertar(persona ** fila, persona * colada, int posicion){
	persona * current;
	current = * fila;
	int i = 1;
	while(current != NULL && i != posicion){//Revisamos condiciones para que avance
		current = current->next;
		i++;
	}
	if (current == NULL || i > contador_fila) return;//Condiciones de "borde"
	if (posicion == 0){//Primer elemento, no deberia darse el caso.
		colada->prev = NULL;
		colada->next = *fila;
		*fila = colada;
		return;
	}	
	/*Cualquier par intermedio*/
	colada->prev = current;
	colada->next = current->next;
	current->next = colada;
}