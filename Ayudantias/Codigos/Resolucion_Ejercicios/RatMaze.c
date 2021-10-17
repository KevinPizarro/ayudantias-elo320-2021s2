#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 25

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct{
	int size;
	Point items[MAXSIZE];//Cada elemento del arreglo es del tipo Point 
}STACK;

void new_move(STACK * ps, Point new_point);
void back(STACK * ps);
void print_moves(STACK * ps);
void StackInit(STACK *ps);
Point new_point(int x, int y);
void print_point(Point point);


int main(int argc, char const *argv[])
{
	
	STACK * ps = (STACK *) malloc(sizeof(STACK));
	StackInit(ps);

	new_move(ps,new_point(0,1));
	new_move(ps,new_point(0,2));
	new_move(ps,new_point(1,2));
	new_move(ps,new_point(2,2));
	new_move(ps,new_point(2,3));
	back(ps);//Eliminamos el punto (2,3)
	new_move(ps,new_point(3,2));
	new_move(ps,new_point(4,2));
	new_move(ps,new_point(4,3));
	new_move(ps,new_point(4,4));
	print_moves(ps);

	free(ps);
	return 0;
}


/*----------------IMPLEMENTACION----------------*/
void new_move(STACK * ps, Point new_point){
	if (ps->size == MAXSIZE)
	{
		fputs("Error: stack overflow\n", stderr);
		abort();
	}
	else{
		ps->items[ps->size ++] = new_point;
	}
}

void back(STACK *ps){
	if (ps->size == 0){
		fputs("Error: Stack underflow\n", stderr);
		abort();
	}
	else
		ps->items[-- ps->size];
}

void StackInit(STACK *ps){
	ps->size = 0;
	new_move(ps, new_point(0,0));// Punto inicial
}
void print_moves(STACK * ps){
	int encabezado = ps->size - 1;
	for (encabezado; encabezado >= 0; encabezado--){
		printf("Movimiento %d: ", encabezado);
		print_point(ps->items[encabezado]);
	}
}

Point new_point(int x, int y){
	Point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

void print_point(Point point){
	printf("(%d,%d)\n", point.x, point.y);
}