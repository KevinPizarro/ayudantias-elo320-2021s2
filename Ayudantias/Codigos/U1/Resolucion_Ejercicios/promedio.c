#include <stdio.h>

int main(void)
{
	int certamenes [] = {0,0,0};//Asumimos 3 certamenes
	float promedio = 0;
	int i = 0;

	printf("Si desea salir del programa antes de calcular el promedio entonces ingrese el caracter 'q'.\n");	
	while( i<3 && certamenes[i]!='q'){
		printf("Ingrese la nota (0-100) del certamen %d: ", (i+1));
		scanf("%d", &(certamenes[i]));
		if(certamenes[i] == (int)'q' || certamenes[i] > 100 || certamenes < 0){//q es equivalente a 117 en ASCII
			printf("Se ha ingresado 'q' o una nota no valida. Saliendo del programa.\n");
			return -1; 
		}
		else{ 
			promedio += certamenes[i];
			i++;
		}
	}
	promedio = promedio/3;
	printf("El promedio es: %f\n", promedio);

	return 0;
}

/*
Si se deseara calcular un promedio ponderado entre certamenes y tareas entonces se debe crear otro arreglo para tareas y repetir el proceso. 
En el calculo final simplemente se le otorga el peso a cada promedio.
*/