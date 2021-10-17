#include <stdio.h>
#include <stdlib.h>

int min(int arr[]), n;
static int i=0,min_val = 999999;

int main(int argc, char const *argv[])
{
	int array [] = {1,2,3,4,5,-100,6,7,8,9,-65464};
	n = sizeof(array)/sizeof(array[0]);
	printf("El valor mínimo del arreglo es: %d.\n", min(array));
	return 0;
}

//Para cada iteración aumenta el i (posicion del arreglo) y guardamos el menor valor hasta ese momento.
int min(int arr[])
{
    if(i < n)
    {
      if(min_val>arr[i])
      	min_val=arr[i];
      i++;
      min(arr);
    }
    return min_val;
}