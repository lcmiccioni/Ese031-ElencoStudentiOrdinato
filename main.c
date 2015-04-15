#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN];
    char cognome[MAX_STRLEN];
    int eta;
    char classe[MAX_STRLEN];
};

// Definisci studente come struct s_studente
struct s_studente studente[N];

// Dichiara il prototipo della funzione di ordinamento
void ordinamento(s_studente);

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati
    for(i=0;i<N;i++) {
        printf("Inserisci il nome dell' alunno numero %d: ", i);
        scanf("%s", studente[i].nome);
        printf("Inserisci il cognome dell' alunno numero %d: ", i);
        scanf("%s", studente[i].cognome);
        printf("Inserisci l'eta' dell' alunno numero %d: ", i);
        scanf("%d", &(studente[i].eta));
        printf("Inserisci la classe dell' alunno numero %d: ", i);
        scanf("%s", studente[i].classe);
    }
    
    // Ordina l'elenco (con funzione)
    ordinamento(studente);
    
    // Codice per la stampa dei dati (uno studente per riga)
    for(i=0;i<N;i++) {
        printf("\n%s, %s, %d, %s", studente[i].nome, studente[i].cognome, studente[i].eta, studente[i].classe);
    }
    
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
void ordinamento(s_studente) {
    int i, j, indiceMin;
    struct s_studente temp;
    
    for(i=0;i<N-1;i++) {
        indiceMin = i;
        
        for(j=i+1;j<N;j++) {
            if((strcmp(studente[j].cognome, studente[indiceMin].cognome))<0)
                indiceMin = j;
        }
        
        if(i!=indiceMin) {
            strcpy(temp.cognome, studente[i].cognome);
            strcpy(studente[i].cognome, studente[indiceMin].cognome);
            strcpy(studente[indiceMin].cognome, temp.cognome);
            
            strcpy(temp.nome, studente[i].nome);
            strcpy(studente[i].nome, studente[indiceMin].nome);
            strcpy(studente[indiceMin].nome, temp.nome);
            
            temp.eta = studente[i].eta;
            studente[i].eta = studente[indiceMin].eta;
            studente[indiceMin].eta = temp.eta;
            
            strcpy(temp.classe, studente[i].classe);
            strcpy(studente[i].classe, studente[indiceMin].classe);
            strcpy(studente[indiceMin].classe, temp.classe);
        }
    }
}