#include <stdio.h>

int main(void)
{
	int array [] = {-5,7,94,0,-88, -98465};
	int i, length, min_value;

	min_value = 2147483647; //maximo valor representable en un int (4bytes o 32bits) -> 2^31 para los positivos y 2^31 para los negativos
	length = sizeof(array)/sizeof(array[0]); 

	for (i = 0; i < length; ++i)
	{
		if(array[i] <= min_value) min_value = array[i];
	}

	printf("El valor mínimo del arreglo es: %d\n", min_value);

	return 0;
}