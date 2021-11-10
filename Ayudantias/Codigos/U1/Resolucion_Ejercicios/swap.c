#include <stdio.h>

void swap(int *, int *);//Prototipo de la funcion swap

int main () {
   int a = 100;
   int b = 200;
 
   printf("Antes del swap, el valor de a : %d\n", a );
   printf("Antes del swap, el valor de b : %d\n", b );
 
   swap(&a, &b);//Llamado a la función swap
 
   printf("Despues del swap, el valor de a : %d\n", a );
   printf("Despues del swap, el valor de b : %d\n", b );
   return 0;
}

/*Definición de la funcion swap*/
void swap(int *x, int *y) {
   int temp;
   temp = *x; 
   *x = *y;   
   *y = temp; 
  
   return;
}