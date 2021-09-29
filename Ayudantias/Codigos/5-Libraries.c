#include <stdio.h> //standard input-output
#include <unistd.h>//UNIX standard, contiene sleep
#include <time.h>  //Para medir tiempos de ejecucion
#include <string.h>//Para trabajar con strings mas facilmente
#include <math.h>  //Contiene funciones matematicas, tal como seno, coseno, atan 
#include <stdlib.h>//standar library. Es la navaja suiza, contiene atoi, malloc, free y entre otras

typedef struct Persona{
	char nombre [50];
	char apellido [50];
	int edad;
}Persona;

int main(int argc, char const *argv[])
{
	double inicial, final, diff;
	inicial = (double) clock();	
	printf("Marca inicial: %f segundos.\n", inicial/CLOCKS_PER_SEC);


	//Ejemplo sleep
	int numero = 5;
	printf("Valor de numero: %d\n", numero);
	numero = 3;
	printf("%s\n", "Esperando 5 segundos");
	sleep(5); //Espera de 5 segundos
	printf("Valor de numero modificado: %d\n", numero);


	//Ejemplo string copy
	Persona persona1;
	//persona1.nombre = "Guts";//Esto está incorrecto
	/*Forma "correcta de hacerlo sin string.h"
	persona1.nombre[0] = 'G';
	persona1.nombre[1] = 'u';
	persona1.nombre[2] = 't';
	persona1.nombre[3] = 's';
	*/
	strcpy(persona1.nombre, "Guts2");//Con libreria string.h
	printf("%s\n", persona1.nombre); //Printeo

	strcat(persona1.nombre, " Berserk");//Concatenacion de string
	printf("%s\n", persona1.nombre);    //Printeo


	//Ejemplo atoi
	char string [5] = "54544";
	//int numerito = (int) string; //Forma incorrecta de transformar
	int numerito = atoi(string);
	printf("Numerito transformado con atoi: %d\n", numerito);


	//Medicion tiempo de ejecucion
	final = (double) clock(); //Marca de tiempo final
	printf("Marca final: %f segundos.\n", final/CLOCKS_PER_SEC);

	diff = final - inicial;
	printf("Tiempo de ejecucion %f segundos\n ", diff/CLOCKS_PER_SEC);//Printeo de tiempo de ejecución

	return 0;	
}
