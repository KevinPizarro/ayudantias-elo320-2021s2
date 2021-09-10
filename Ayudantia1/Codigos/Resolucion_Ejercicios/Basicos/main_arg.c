#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("El nombre del programa es: %s\n", argv[0]); //Notar que siempre tendremos como argumento el nombre del programa
	if (argc == 1)
	{
		printf("No se ha ingresado más argumentos.\n");
	}
	else{
		int i;
		for (i = 0; i < argc; ++i)
		{
			printf("Argumento %d: %s\n", i,argv[i]);
		}
	}
	return 0;
}