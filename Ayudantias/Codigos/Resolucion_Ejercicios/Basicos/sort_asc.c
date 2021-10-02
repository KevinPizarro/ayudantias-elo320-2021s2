#include <stdio.h>

int main(void)
{
	int my_array [5];
	int i, j, temp, length;

	for (i = 0; i < 5; ++i)
	{
		printf("Ingrese el valor del elemento %d del arreglo: ", i+1);
		scanf("%d", &(my_array[i]));
	}


	length = sizeof(my_array)/sizeof(my_array[0]); 
	for (i = 0; i < length; ++i)
	{
		for (j = i; j < length; ++j)
		{
			if(my_array[j] < my_array[i]){
				temp = my_array[i];
				my_array[i] = my_array[j];
				my_array[j] = temp;
			}
		}
	}

	for (i = 0; i < length; ++i)
	{
		printf("%d ; ", my_array[i]);
	}

	return 0;
}


/*
Hay multiples formas para ordenar, esta es la mas intuitiva pero una de las mas costosas. Mas adelante se analizara en conjunto a otros algoritmos.

Si se quisiera probar para 100 números o más, lo mejor seria inicializarlos en un arreglo con numeros random y tomar el tiempo de ejecucion. 
Luego comparar para 10,100 1000, 10000
*/