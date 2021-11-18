/*Dato un numero intero n, scrivere un algoritmo che scriva
quali e quanti fattori primi ha.*/
#include <stdio.h>

int main (){
	int n;
	int i = 2;
	int counter = 1;
	
	printf("Inserire il valore ");
	scanf("%d", &n);
	printf("Fattori: ");
	
	for (i; i<n; i++){
		if (n%i == 0){
			n = n / i;
			counter += 1;
			printf("%d ", i);
			i = 1;
		}
	}
	printf("%d ", n);
	printf("\nI fattori sono: %d", counter);
}
