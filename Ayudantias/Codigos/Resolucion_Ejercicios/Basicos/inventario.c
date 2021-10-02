#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 10

typedef struct Objects{
	int id;
	int amount;
	char description [100];
	int price;
}Object;

int new_object(int , int , char * , int , int , Object * );
int delete_object(int , Object * );
int info_object(int index, Object * main_storage);

int main(void)
{
	Object storage [ARRAY_SIZE];
	new_object(1,10,"Chokita", 350, 0, storage);
	info_object(0, storage);
	delete_object(1, storage);
	info_object(0, storage);
	return 0;
}


/*-----------------------------IMPLEMENTACION FUNCIONES-----------------------------*/
int new_object(int new_id, int new_amount, char * new_description, int new_price, int index, Object * main_storage){
	main_storage[index].id = new_id;
	main_storage[index].amount = new_amount;
	strcpy(main_storage[index].description, new_description);
	main_storage[index].price = new_price;
	printf("Se ha añadido el nuevo objeto.\n");
	return 1;
}

int delete_object(int id_search, Object * main_storage){
	int i, length;
	length = ARRAY_SIZE;
	for (i = 0; i < length; ++i)
	{
		if (main_storage[i].id == id_search)
		{
			main_storage[i].id = 999;
			main_storage[i].amount = -1;
			strcpy(main_storage[i].description, "NULL");
			main_storage[i].price = -1;
			printf("Se ha eliminado el objeto.\n");
			break;
		}
	}
	return 1;
}

int info_object(int index, Object * main_storage){
	printf("En el inventario el objeto N° %d es '%s' el cual tiene como id %d, precio %d y tiene a disposición %d unidades.\n", index, main_storage[index].description, main_storage[index].id, main_storage[index].price, main_storage[index].amount);
	return 1;
}
