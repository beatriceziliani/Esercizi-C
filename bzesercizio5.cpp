/*5. Scrivere una funzione che stampi la serie di Fibonacci per i primi n numeri interi (n inserito
dall’utente).
Es. n=6 -> 1 1 2 3 5 8*/
#include <stdio.h>

int main(){
    int n;
    int numero = 0;
    int i = 0;
    
    
    printf("Inserisci la quantità di numeri per la serie di Fibonacci ");
    scanf("%d", &n);
    int lista[n];
    
    for (i; i<n; i++){
        lista[i] = numero;
        numero += lista [i-1];
        if (numero == 0){
		numero += 1;
		}
		printf("%d\n",numero);
    }
}
