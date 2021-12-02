#include <stdio.h>
enum COLOR {RED,GREEN,BLUE};//enumeramos las "variables" RED,GREEN,BLUE. Toman como valores 0,1 y 2 respectivamente.

int main(void)
{
	//Condicionales: <, >, >=, <=, ==, !=, &&, ||
	//Operadores aritmeticos: +,-,*,/,%

	/*----------------IF/ELSE----------------*/
	unsigned short int num1 = 2;
	unsigned short int num2 = 5;
	unsigned short int num3 = 7;
	unsigned short int num4 = 11;

	enum COLOR color;
	color = RED;

	if(num1 < num2){
		printf("Sí, efectivamente num1 es menor que num2.\n");
	}
	if(1) printf("if en una sola línea.\n");//1 es igual a decir true y 0 es igual a decir falso


	if((num4 >= num1) && (num2<num1)){ // AND
		printf("num 4 es mayor igual que num1 y además num2 es menor que num1.\n");
	}
	else{
		printf("Alguna de las expresiones no se cumple...\n");
	}

	/*if-else anidados*/
	if((num4 >= num1) && (num2<num1)){ 
		printf("num 4 es mayor igual que num1 y además num2 es menor que num1.\n");
	}
	else if(num4 >= num1){
		printf("num2 es mayor o igual a num1.\n");
	}
	else printf("num4 es menor que num1.\n");



	/*----------------SWITCH-CASE----------------*/

	switch(color){/*Si se omiten los breaks entonces se ejecutan todos los casos, salvo default*/
		case RED:
			printf("El color es rojo con valor.\n");
			break; //Casi por obligación, hay casos en que no.
		case BLUE:
			printf("El color es azul.\n");
			break;
		case GREEN:
			printf("El color es verde.\n");
			break;
		default:
			printf("No era ninguno de los enumerados.\n");
	}
	/*----------------FOR----------------*/
	int i = 0;
	int max = 10;
	
	for (i = 0; i <= 10; ++i){/*Imprime todos los numeros de 0 a 10*/
		printf("Número %d\n",i);
	}
	
	
	for (i = 0; i <= 10; ++i){/*Imprime todos los numeros de 0 a 10, salvo el 5*/
		if(i==5) continue;
		printf("Número %d\n",i);
	}
	

	/*----------------WHILE----------------*/
	char string[] = "General Kenobi";
	//Otra opción de calcular el largo: librería string.h -> metodo stringlen(string). 
	int str_len = sizeof(string)/sizeof(string[0]);//Se prefiere esta forma puesto que es extrapolable a otros casos.
	int index = 0;
	
	while(index < str_len){
		printf("%c\n",string[index]);
		index++;
	}
	
	return 0;
}

//Otro control de flujo: goto
//No es recomendable utilizarlo, preferiblemente evitarlo y olvidar su existencia.

/*Referencias
https://www.geeksforgeeks.org/enumeration-enum-c/
https://www.geeksforgeeks.org/decision-making-c-c-else-nested-else/
https://www.geeksforgeeks.org/loops-in-c-and-cpp/
Libro: The C programming language
*/