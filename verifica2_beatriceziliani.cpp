/*

7) Modificare la funzione Insert per consentire in caso di LIMITE MASSIMO DI ELEMENTI RAGGIUNTO l'inserimento
di un nuovo record utilizzando, se disponibile, un qualsiasi record eliminato permanentemente dal cestino.


*/



#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 6
#define MAXSTR 15

typedef struct {
	int id;
  	char cognome[MAXSTR];
	char nome[MAXSTR];  
} s_arch;


s_arch archivio[N]={ 
	{1,"Rossi", "Mario"},
	{2,"Verdi", "Ugo"},
	{3,"Gagliardi", "Giovanni"},
	{4,"Plutone", "Pippo"},
};

int cancellati[N];

void Visualizza(int pos)
{ 
int i=0, j;
bool cancellato = false;
while(i<pos)
{
	if(archivio[i].id <= 0){
		cancellato = true;
	}
		/*
	printf("\n%d\n",archivio[i].id);
	printf( cancellato ? "true" : "false");*/
	}
	if (cancellato == false){
		
		printf("\n\n     ID:%d", archivio[i].id);
 		printf("\n COGNOME:%s ", archivio[i].cognome);
		printf("\n    NOME:%s ", archivio[i].nome);
	}	
	cancellato = false;

	i++;
 }


void Cestino(int pos)
{ 
int i=0, j;
bool cestino = false;
bool controllo = false;
while(i<pos)
{
	if(archivio[i].id < 0){
		cestino = true;
		controllo = true;
	}
	
	if (cestino == true){
		
		
		printf("\n\n     ID:%d", archivio[i].id);
 		printf("\n COGNOME:%s ", archivio[i].cognome);
		printf("\n    NOME:%s ", archivio[i].nome);
	}	
	cestino = false;

	i++;
}
if(controllo == false){
	printf("\nIl cestino e' vuoto\n");
} 
}

int Insert(int pos)
{

	if(pos>=N) {
		printf("\n\nHAI RAGGIUNTO IL LIMITE MASSIMO DI ELEMENTI");
		
	return(pos);
	}
	
	archivio[pos].id = pos+1;
	
	printf("\nNuovo Rcd n. %d:", pos);
	printf("\nCOGNOME:");
	scanf("%s",archivio[pos].cognome);
	printf("   NOME:");
	scanf("%s",archivio[pos].nome);

	pos++;
	return(pos);
}

void VisualizzaByCognome(int pos)
{ 
	char cognome[MAXSTR];
	int i=0, trovato=0, j;
	bool cancellato = false;
	printf("\nQuale cognome cerchi?:");
 	scanf("%s", cognome);
 	
	for (i=0; i<pos; i++){
	 	if(strcmp(archivio[i].cognome,cognome)==0) {
				if(archivio[i].id <= 0){
					cancellato = true;
			}
			if (cancellato == false){
	 			printf("\n\n     ID: %d ", archivio[i].id);
	 			printf("\nCOGNOME: %s ", archivio[i].cognome);
	 			printf("\n   NOME: %s ", archivio[i].nome);
	 			trovato=1;
	 		}
			}
	 		cancellato = false;
		 }
 	
 	if (trovato==0) 
		 printf("\nCOGNOME CERCATO NON PRESENTE");
}

void CancellazioneLogica(int pos){
	int id, i;
	printf("Inserire l'indice del record che vuoi cancellare\n");
	scanf("%d",&id);	
	i = id - 1;
	archivio[i].id = -id;
	cancellati[i] = -id;
}	

void Ripristina(int pos){
	int id, i;
	printf("Inserire l'indice del record che vuoi ripristinare\n");
	scanf("%d",&id);
	i = id - 1;
	archivio[i].id = id;
	cancellati[i] = 0;
	
}

void Eliminazione(int pos){
	int id, i, j;
	bool cestino = false;
	printf("Inserire l'indice dell'elemento che vuoi eliminare in maniera permanente\n");
	scanf("%d",&id);
		if (archivio[i].id == cancellati[j]){
		cestino = true;
	}
	if (cestino == true){
		print(cestino ? "true" : "false");
		
	}
	i = id - 1;
	archivio[i].id = 0;
	
}
int menu_scelta(void)
{
  int selezione = 0;
  do
    {
    printf("\n" );
    printf("\n0 -> Esci");
    printf("\n1 -> Visualizza Archivio" );
    printf("\n2 -> Inserisci");
    printf("\n3 -> Ricerca");
    printf("\n4 -> Cancellazione Logica");
    printf("\n5 -> Visualizza Cestino");
    printf("\n6 -> Ripristina Contatto");
	printf("\n7 -> Eliminazione permanente");    
    printf("\n" );
    printf("\nEffettua una scelta -> " );
    scanf("%d", &selezione );
    }
    while (selezione < 0 || selezione > 7);
  return selezione;
}

int main(void)
{
    int MyIndex=4; //indico il numero di elementi allocati nel vettore archivio
    int scelta;
    
    while((scelta=menu_scelta())!=0){
    switch(scelta){
        case 1: 
               Visualizza(MyIndex);
               break;
        case 2:
               MyIndex=Insert(MyIndex);
               break;
        case 3:
               VisualizzaByCognome(MyIndex);
               break;
        case 4:
               CancellazioneLogica(MyIndex);
               break;
        case 5:
               Cestino(MyIndex);
               break;
        case 6:
               Ripristina(MyIndex);
               break;
        case 7:
        		Eliminazione(MyIndex);
        		break;
             }
    }             
    return 0;
}
