#include <stdio.h>

int main(void)
{
    unsigned char string[100];//String de máximo 100 caracteres.
    char *ptr; //Puntero que recorrerá el string.
    unsigned short int contador_vocales=0; //contador

    printf("Ingrese un string de máximo 100 caracteres: ");
    fgets(string, 100, stdin); //Lectura

    ptr=string;

    while(*ptr!='\0')
    {
        if(*ptr=='A' ||*ptr=='E' ||*ptr=='I' ||*ptr=='O' ||*ptr=='U'
        		||*ptr=='a' ||*ptr=='e' ||*ptr=='i' ||*ptr=='o' ||*ptr=='u')
            contador_vocales++;
        ptr++;//Apuntamos al proximo caracter
    }

    printf("Cantidad de vocales en el string: %hu\n",contador_vocales);
    return 0;
}