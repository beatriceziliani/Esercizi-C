#include <stdio.h>

int main()
{
int n = 0;
int a = 1;
int somma = 0;

printf("Di quanti numeri dispari vuoi la somma?");
scanf("%d", &n);

for(a; a<=n; a ++){
    somma = somma + a + 2;
}
printf("%d", somma);
    return 0;
}
