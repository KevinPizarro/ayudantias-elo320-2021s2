#include <stdio.h>
#include <math.h> //Para elevar a n

int main()
{
	double VF, VI, i, n;

	printf("Ingrese el capital inicial: ");
	scanf("%lf", &VI);
	printf("Ingrese la tasa de interés en %: ");
	scanf("%lf", &i);
	i /= 100;
	printf("Ingrese la cantidad de periodos: ");
	scanf("%lf", &n);

	VF = VI*pow(i+1,n);//pow tambien puede ser implementado desde 0, pero es mejor no reinventar la rueda
	printf("El capital final sera de: %lf\n", VF);

	return 0;
}

//Si se tienen problemas con la funcion pow, se debe compilar de la siguiente forma
// gcc nombre_programa.c -lm