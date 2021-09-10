#include <stdio.h> //Esto es una directiva de preprocesador, permite incluir la librería stdio.h (standard input/output)

int main(void)
{
	printf("\n---------------------------INT---------------------------\n\n");
	int entero1 = 1; 		  
	unsigned int entero2 = 2; 
	short int entero3 = 3;
	unsigned short int entero4 = 4;
	long int entero5 = 5;
	unsigned long int entero6 = 6;
	printf("El entero1 es de tamaño %d bytes y tiene valor %d\n" , sizeof(entero1), entero1);
	printf("El entero2 es de tamaño %d bytes y tiene valor %u\n" , sizeof(entero2), entero2);
	printf("El entero3 es de tamaño %d bytes y tiene valor %hi\n", sizeof(entero3), entero3);
	printf("El entero4 es de tamaño %d bytes y tiene valor %hu\n", sizeof(entero4), entero4);
	printf("El entero5 es de tamaño %d bytes y tiene valor %ld\n", sizeof(entero5), entero5);
	printf("El entero6 es de tamaño %d bytes y tiene valor %lu\n", sizeof(entero6), entero6);

	printf("\n---------------------------CHAR---------------------------\n\n");
	char caracter1 = 'a';
	unsigned char caracter2 = 'b';
	printf("El caracter1 es de tamaño %d bytes y tiene valor %c\n", sizeof(caracter1), caracter1);
	printf("El caracter2 es de tamaño %d bytes y tiene valor %c\n", sizeof(caracter2), caracter2);

	printf("\n---------------------------FLOAT---------------------------\n\n");
	float decimal1 = -1.254;
	double decimal2 = 1.7e-2; //Otra forma de escribir 0.017
	long double decimal3 = 1.2F; //Otra forma de escribir 1.2
	printf("El decimal1 es de tamaño %d bytes y tiene valor %f\n", sizeof(decimal1), decimal1);
	printf("El decimal2 es de tamaño %d bytes y tiene valor %lf\n", sizeof(decimal2), decimal2);
	printf("El decimal3 es de tamaño %d bytes y tiene valor %Lf\n", sizeof(decimal3), decimal3);


	printf("\n---------------------------OTROS CASOS---------------------------\n\n");
	printf("Este es un unsigned short int: %hu\n", -1);//Le pasamos un valor negativo a algo que declaramos como un entero sin signo
	printf("Este es un signed short int: %hi\n", 32768);//Le pasamos un valor que excede el valor máximo que se puede representar
	printf("Este es un signed char: %c\n", -20);//Le pasamos un valor que no es representable por ASCII
	printf("Este es un signed char: %c\n", 97);//Le pasamos un valor que SI es representable por ASCII
	printf("\n");
	return 0;
}

/*Referencia: 
https://www.decodejava.com/data-types-in-c.htm
https://theasciicode.com.ar/
Libro: The C programming language
*/