#include <stdio.h>

int sumatoria(int a, int b);

int main(int argc, char const *argv[])
{
	int a = 1;
	int b = 4;
	int result = sumatoria(a,b);
	printf("Resultado: %d\n", result);
	return 0;
}

int sumatoria(int a, int b){
	if( a > b ) return 0;// condición de finalizado
	else{
		return sumatoria(a+1,b) + a; //Qué es lo que me interesa de iteración actual y que le paso a la siguiente?
	}
}