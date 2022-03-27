/* Esempio di programma base da completare
per il test statistico dell'algoritmo
di ordinamento per selezione */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <math.h>

#define N 10000 // N Massimo Numero Elementi

int V[N]; // Vettore di interi per il test

const int test=1; // Flag per il test=1

void Visualizza(int n) {
// SE TEST==1 La funzione visualizza gli elementi del vettore
    int i;
    for (i=0; i<n; i++){
        if (test==1){
            printf("%d  ", V[i]);
        }
    }

}


void InsRnd(int n){
// Inserisce nel vettore V e B numeri casuali da 1 a n
    int i,MyRand;
 
    srand(time(0));  // radice random    
    for (i=0; i<n; i++ )
      {
          MyRand=rand() % n +1 ;  //Generazione n numeri casuali da 1 a n
          printf("%d  ",MyRand);
          V[i]=MyRand;
      }

}


void Scambia(int a, int b){
   
    int i,tmp;
   
    if (test==1) printf("(Scambio %d e %d)", V[a],V[b]);
   
    tmp=V[a];
    V[a]=V[b];
    V[b]=tmp;

}

void OrdinaSel(int n) {

// Ordinamento per selezione
    int i, j, min, t;
    for(i=0; i<n-1; i++){
      min=i;
      for (j=i+1; j<n; j++){
         if (V[j]<V[min])
            min=j;
      }
      Scambia(min, i);
      /*
      t = V[min];
      V[min] = V[i];
      V[i] = t;
      */
    }

}


void OrdinaBubble(int n) {

// Ordinamento Bubble
    int i, j;
    // N.B. n-1 è l'ultima componente dell'array.
    for(i=0; i<n; i++) //scansiona tutto l'array tranne l'ultima componente: n - 1 escluso. Quindi fino al penultimo elemento.
        for (j=0; j<n-1; j++) //j settato all'ultima componente e decresce ad ogni iterazione. Esce dal ciclo solo se j <= i
            if (V[j]>V[j+1])  //se la componente corrente è più piccola della precedente, li scambia.
                Scambia(j, j+1);
}

int main() {

    int elem;
    int risp;
    double tempSel;
   
    printf ("Inserire elementi test max[%d] " ,N);
    scanf("%d",&elem);
   
    InsRnd(elem);
    printf("\nVettore[%d] inserito Random\n",elem);
   
    Visualizza(elem);
    printf("\nOrdinamento selezione\n");
   
    printf("Vuoi ordinare per selezione (inserisci 1) oppure con Bubble (inserisci 2): ");
    scanf("%d",&risp);
   
    clock_t start = clock();
   
    if (risp==1){

        OrdinaSel(elem);

    }
    if (risp==2){

        OrdinaBubble(elem);
   
    }
   
    clock_t end = clock();
   
    printf("\nVettore[%d] ordinato\n",elem);
    Visualizza(elem);
    // Visualizzare il tempo impiegato (tempSel)
    printf("\n Tempo di esecuzione =  %f secondi \n", ((double)(end - start)) / CLOCKS_PER_SEC);
   
    return 0;
   
}
