#include <stdio.h>
#include <string.h>
void main(void){

	char string[100]; 
	int lenght,i;

	printf("\nIngrese el string a invertir: ");
	fgets(string, sizeof(string), stdin);//scanf puede funcionar igualmente, bajo las condiciones de esta funcion
	lenght = strlen(string);//Tambien se puede calcular con sizeof(string)/sizeof(string[0]) tomando en consideracion los espacios no utilizados del arreglo
	
	printf("El string en reversa es: ");
	for(i=lenght; i>=0;i--){
		printf("%c", string[i]);
	}
	printf("\n");
}