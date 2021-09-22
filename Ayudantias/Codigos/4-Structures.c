#include <stdio.h>

//Estructura llamada Pokemon que tiene 5 "atributos".
struct Pokemon{
	char * nombre;
	int nivel;
	int n_pokedex;
	char * tipo1;
	char * tipo2;
};

//Estructura llamada Entrenador_Pokemon que tiene 4 "atributos", uno de ellos un arreglo de estructuras Pokemon.
struct Entrenador_Pokemon
{
	char * nombre;
	int id;
	int edad;
	struct Pokemon pokemones[3];
}entrenador={"Brock", 2, 88};


//void initialize(struct Entrenador_Pokemon *, char *);
void print_trainer_info(struct Entrenador_Pokemon *);

int main(int argc, char const *argv[])
{

	//¿Qué pasa si eliminamos la palabra reservada "struct"?
	struct Entrenador_Pokemon Entrenador1;
	//¿Qué pasa si printeamos el nombre sin definirlo?
	Entrenador1.nombre = "Ash ";
	initialize(&Entrenador1, "Ash1");
	printf("%s\n", Entrenador1.nombre);
	Entrenador1.id = 10101;
	Entrenador1.edad = 87;
	Entrenador1.pokemones[0].nombre = "Bulbasaur (Besto pokemon)";
	Entrenador1.pokemones[0].nivel = 99;
	Entrenador1.pokemones[0].n_pokedex = 1;
	Entrenador1.pokemones[0].tipo1 = "Planta";
	Entrenador1.pokemones[0].tipo2 = "Veneno";//Probar puntero a NULL

	printf("\n El primer pokemon de %s es %s, con un nivel %i.\n\n", Entrenador1.nombre, Entrenador1.pokemones[0].nombre, Entrenador1.pokemones[0].nivel);
	print_trainer_info(&entrenador);

	/*
	typedef int my_int;
	typedef struct Point Point;
	*/

	typedef int my_int;
	typedef struct Point{
		int x = 0;
		int y = 0;
	}Point;

	my_int a = 1;
	printf("My int is: %i\n", a);

	Point punto;
	Point punto2;

	punto2.x = 1;
	punto2.y = 2;

	printf("Mi punto en el espacio es (%i,%i)\n", punto.x,punto.y);
	printf("Mi punto 2 en el espacio es (%i,%i)\n", punto2.x,punto2.y);
	return 0;
}

void initialize(struct Entrenador_Pokemon * ep1, char * nombre_entrenador){
	(*ep1).nombre = nombre_entrenador;
}

void print_trainer_info(struct Entrenador_Pokemon * trainer){
	printf("El entrenador %s tiene %i años y su id es %i.\n", (*trainer).nombre, (*trainer).edad, (*trainer).id);
}

/* REFERENCIAS
Typedef struct vs struct: https://www.youtube.com/watch?v=dByGjQyLJww
Typedef: https://www.tutorialspoint.com/cprogramming/c_typedef.htm
*/