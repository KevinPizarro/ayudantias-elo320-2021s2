#include <stdio.h>
#include <stdlib.h>

static int * q;
static int N, cabeza, cola, encolados; 

void init(int MAXN);
void new_data(int a);
int read_data();
void print_all();

int main(int argc, char const *argv[])
{
	init(20);
	int i=0, sec = 0;

	for(i; i<5; i++){
		new_data(i);
	}

	while(i<15){
		if (sec % 2 == 0)//Usar sec%2 == 1 para otra logica.
		{
			new_data(i);
			sleep(sec);
			sec = 0;
		}
		else{
			sleep(sec);
			printf("Saco dato: %d\n", read_data());
		}
		sec ++;
		i ++;
		printf("Datos en cola: \n");
		print_all();
	}
	return 0;
}

/*---------------------IMPLEMENTACION-------------------------*/

void init(int MAXN){
    q = malloc((MAXN)*sizeof(int));
    N = MAXN+1 ; cabeza = 0; encolados = 0; cola = 0;
}

void new_data(int a){
    if(encolados < N){
        q[cola] = a;
        cola = (cola + 1) % N;
        encolados++;
    }
}

int read_data(){
    int consumido = q[cabeza];
    cabeza = (cabeza + 1) % N;
    encolados--;
    return(consumido); 
}

void print_all(){
    int cursor;
    for(cursor = cabeza; cursor < cola; cursor++)
        printf("%d\n", q[cursor]);  
}