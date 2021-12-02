#include<stdio.h>
#define SIZE 100 //Directiva de preprocesamiento define

int main(){
   char string[SIZE];
   int index;

   printf("Ingrese el string de máximo 100 caracteres: ");
   fgets(string ,SIZE, stdin);
   int length = sizeof(string)/sizeof(string[0]);

   for(index=0; index<=length; index++){
      if(string[index]>=97&&string[index]<=122)
         string[index]=string[index]-32; //Notar esa relación de la tabla ASCII
   }
   printf("El string en mayúsculas es: %s",string);
   return 0;
}