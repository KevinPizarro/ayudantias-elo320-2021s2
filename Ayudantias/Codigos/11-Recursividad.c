#include<stdio.h>

//Implementación para sucesión de Fibonacci hasta número n.
int fibo(int n){
	if(n <= 1) return n;//Condición de termino
	return fibo(n-1) + fibo(n-2);//Lo que voy a iterar
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Ingrese el número a calcular la sucesión de Fibonacci: ");
	scanf("%d", &n);
	printf("La sucesión de Fibonacci hasta %d es: %d.\n",n, fibo(n));
	return 0;
}

/*
fibo(4) = fibo(3) + fibo(2)
		= (fibo(2) + fibo(1)) + (fibo(1)+fibo(0))          //fibo(1) = 1 y fibo(0) = 0
		= ((fibo(1) + fibo(0)) + 1) + (1 + 0)
		= 1 + 0 + 1 + 1 + 0
		= 3
*/

/* Calculadora Fibonacci
https://www.omnicalculator.com/math/fibonacci
*/