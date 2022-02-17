#include <stdio.h>
#include <string.h>

#define N 9
#define MAXSTR 15
#define ISCRIZIONI "AGENDA.txt"

struct s_arch{
    int id;
    char cognome[MAXSTR];
    char nome[MAXSTR];
    char cell[MAXSTR];
};


s_arch archivio[N]={
    {1,"Gagliardi","Giovanni" ,"337"},
    {2,"Plutone", "Pippo", "324"},
    {3,"Rossi", "Mario","123"},
    {4,"Verdi", "Ugo", "322"}
};

int MyIndex = 4;
//indico il numero di elementi allocati nel vettore archivio


void view(int i){
    printf("\n\n     ID:%d", archivio[i].id);
    printf("\n COGNOME:%s ", archivio[i].cognome);
    printf("\n    NOME:%s ", archivio[i].nome);
    printf("\nTELEFONO:%s ", archivio[i].cell);
}

void Visualizza(int pos)
{
    int i = 0;
    while(i < pos)
    {
        view(i);
        i++;
    }
}

int Insert(int pos)
{
    char invio;
    char c;

    if(pos >= N) {
        printf("\n\nHai raggiunto il limite massimo di elementi ");

        scanf("%c", &invio);
        return(pos);
    }

    archivio[pos].id = pos + 1;

    printf("\nNuovo Rcd n. %d:", pos);
    printf("\nCOGNOME:");
    scanf("%s",archivio[pos].cognome);
    printf("   NOME:");
    scanf("%s",archivio[pos].nome);
    printf("TELEFONO:");
    scanf("%s",archivio[pos].cell);

    pos++;
    return(pos);

}

void VisualizzaByCognome(int pos)
{
    char cognome[MAXSTR];
    int i=0, trovato=0;

    printf("\nQuale cognome cerchi?:");
    scanf("%s", cognome);
    
    for (i=0; i<pos; i++){
        if(strcmp(archivio[i].cognome,cognome)==0) {
            view(i);
            trovato=1;
    }
  }
  if (trovato==0)
    printf("\nNon e' presente il cognome cercato:");
}

void VisualizzaByNome(int pos)
{
    char nome[MAXSTR];
    int i=0, trovato=0;

    printf("\nQuale nome cerchi?:");
    scanf("%s", nome);
    
    for (i=0; i<pos; i++){
        if(strcmp(archivio[i].nome,nome)==0) {
            view(i);
            trovato=1;
        }
    }
    if (trovato==0)
        printf("\nNon e' presente il nome cercato:");
}

void VisualizzaByTelefono(int pos)
{
    char cell[MAXSTR];
    int i=0, trovato=0;

    printf("\nInserisci il numero di telefono che cerchi:");
    scanf("%s", cell);
    
    for (i=0; i<pos; i++){
        if(strcmp(archivio[i].cell,cell)==0) {
            view(i);
            trovato=1;
        }
    }
    if (trovato==0)
        printf("\nNon e' presente il telefono cercato:");
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
    printf("\n3 -> Ricerca per cognome");
    printf("\n4 -> Ricerca per nome");
    printf("\n5 -> Ricerca per numero di telefono");
    printf("\n6 -> Ordina per numero");
    printf("\n7 -> Cambia nome di un utente dall'indice");
    printf("\n" );
    printf("\nEffettua una scelta -> " );
    scanf("%d", &selezione );
    }
    while (selezione < 0 || selezione > 7);
  return selezione;
}

void Scambia(int i, int j)
{

    s_arch tmp;
    strcpy (tmp.cognome, archivio[i].cognome);
    strcpy (tmp.nome, archivio[i].nome);
    strcpy (tmp.cell, archivio[i].cell);

    strcpy (archivio[i].cognome, archivio[j].cognome);
    strcpy (archivio[i].nome, archivio[j].nome);
    strcpy (archivio[i].cell, archivio[j].cell);
   
    strcpy (archivio[j].cognome, tmp.cognome);
    strcpy (archivio[j].nome, tmp.nome);
    strcpy (archivio[j].cell, tmp.cell);

}

void Salva(int pos)
{
	pos = MyIndex;
    FILE *out;
    out = fopen(ISCRIZIONI,"w"); //apertura del file append
    if (out)
    {
        for (int i = 0; i < pos; i++)
        {
            fprintf(out,"  Cognome: %s\n", archivio[i].cognome);
            fprintf(out,"     Nome: %s\n", archivio[i].nome);
            fprintf(out,"Telefono: %s\n", archivio[i].cell);

        }
        fclose(out);    
    }
}


void Ordina(int pos)
{
    for (int k = 0; k < pos; k++)
    {
        for (int x = k + 1; x < pos; x++)
        {
            if (strcmp(archivio[k].cognome, archivio[x].cognome) > 0)
            {
                Scambia(k, x);
            }
        }
    }
}

void SortByNumber(int pos){
    for(int k = 0; k < pos; k++){

        for(int j = k+1; j < pos; j++){
            
            if(strcmp(archivio[k].cell, archivio[j].cell) > 0){

                Scambia(k,j);

            }
        }

    }
}

void UpdateNameByIndex(int pos){
    int index = 0;
    char name[MAXSTR];

    printf("\nQuale indice vuoi modificare? ");
    scanf("%d", index);

    printf("\nIn cosa lo vuoi cambiare? ");
    scanf("%s", name);

    // questo copia il secondo argomento nel primo
    strcpy(archivio[index - 1].nome,name);
}


int main(void){

    int scelta;
   
    while(( scelta = menu_scelta() ) != 0){
   
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
                VisualizzaByNome(MyIndex);
                break;
            case 5:
                VisualizzaByTelefono(MyIndex);
                break;
            case 6:
                SortByNumber(MyIndex);
                break;
            case 7:
                UpdateNameByIndex(MyIndex);
                break;
            }
        
    }
    
	Ordina(MyIndex);
	Salva(MyIndex);

    return 0;
}
