/*Generare la serie dei quadrati dei primi n numeri naturali (n letto da input).
*/
#include <stdio.h>

int main (){
	int n;
	int i = 0;
	
	printf("Stabilisci quanti numeri inserire nella serie dei quadrati ");
	scanf("%d", &n);

	for (i; i<n; i++){
		printf("%d", i*i);
	}
}
