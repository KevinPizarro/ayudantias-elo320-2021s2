#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player{
	char name [50];
	int id_player;
	int debt;
	struct Player * next;	
}Player;

Player * new_player (char * name, int id_player, int debt);//Crea un nuevo jugador
void push (Player ** list, Player * player);//Agrega un jugador a la lista
Player * get (Player * list, int ID);//Busqueda por ID
void print_list(Player * head); //Printea la lista completa.
void delete (Player ** list, int X);//Elimina al jugador en la posicion X según la cabeza.

int main(int argc, char const *argv[])
{
	/*Prueba sin interaccion administrador
	int i, counter_player = 0;
	Player * jugador1 = new_player("Pepito Grillo", 1, 1000);
	Player * jugador2 = new_player("Goku", 2, 70000);
	Player * jugador3 = new_player("Ranma", 3, 140000);

	Player * list = NULL;
	push(&list, jugador1);
	push(&list, jugador2);
	push(&list, jugador3);
	print_list(list);

	Player * to_search;
	to_search = get(list, 1);
	printf("Se ha encontrado a %s, con ID %d y deuda %d.\n", to_search->name, to_search->id_player, to_search->debt);

	counter_player =3;
	for (i = 1; i <= counter_player; counter_player--){
		delete(&list, 1);
	}
	print_list(list);
	*/

	//Con interaccion
	int i, option, flag = 1, counter_player = 0;
	
	Player * list = NULL;
	Player * player;
	char name [50];
	int debt, id_player, position;
	

	printf("Bienvenido a la administración de Squid Game. ");
	while(flag){
		printf("\n\n-------------------------------------------------------\nPor favor, seleccione la opción de su interés.\n\n1. Crear un nuevo jugador.\n2. Añadir un nuevo jugador a la lista.\n3. Obtener la información de un jugador según su ID.\n4. Obtener la información de todos los jugadores de la lista.\n5. Eliminar a un jugador.\n0. Salir del programa.\n\n");
		scanf("%d", &option);
		switch (option){
			case 0:
				printf("Saliendo del programa.\n");
				flag = 0;
				break;
			case 1:
				printf("Ingrese el sólo el nombre del jugador: ");
				scanf("%s",name);
				printf("Ingrese el id del jugador: ");
				scanf("%d", &id_player);
				printf("Ingrese la deuda del jugador: ");
				scanf("%d", &debt);
				player = new_player(name,id_player,debt);
				break;
			case 2:
				push(&list, player);
				counter_player ++;
				break;
			case 3:
				printf("Ingrese el ID a buscar: ");
				scanf("%d", &id_player);
				player = get(list, id_player);
				if (player != NULL) printf("Se ha encontrado al jugador %s con deuda %d.\n", player->name, player->debt);
				else printf("No se ha encontrado al jugador con id %d.\n", id_player);
				break;
			case 4:
				print_list(list);
				break;
			case 5:
				printf("Ingrese la posición del jugador a eliminar: ");
				scanf("%d", &position);
				delete(&list, position);
				counter_player--;
				break;
			default:
				printf("No ha sido ingresada una opción válida.\n");
				break;
		}
		printf("\n");
	}
	for (i = 1; i <= counter_player; counter_player--){
		delete(&list, 1);
	}
	return 0;
}



/**---------------------IMPLEMENTACION FUNCIONES---------------------*/
Player * new_player (char * name, int id_player, int debt){
	Player * new_player = (Player *) malloc(sizeof(Player));
	strcpy(new_player->name, name);
	new_player->id_player = id_player;
	new_player->debt = debt;
	return new_player;
}

void push (Player ** list, Player * player){
	player->next = *list;
	*list = player;
}


Player * get (Player * list, int ID){
	Player * temp = list;
	while (temp != NULL){
		if (ID == temp->id_player)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void print_list(Player * nodito){
	while (nodito != NULL){
		printf("Nombre de jugador:%s \n Id jugador: %d\n Deuda: %d\n-------------------------\n", nodito->name, nodito->id_player, nodito->debt);
		nodito = nodito->next;
	}
}

void delete (Player ** list, int X){
	Player * temp = *list;
	int position = 1;
	while(temp != NULL){
		if (position == 1) {
			*list = temp->next;
			free(temp);
			return;
		}
		if (position+1 == X)//Estoy en el nodo anterior al que será borrado
		{
			temp->next = temp->next->next;
			free(temp->next);
			return;
		}
		position++;
		temp = temp->next;
	}
	return;
}