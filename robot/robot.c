/*PARTE 1
Si scriva un programma C che legge il file robots.txt e visualizza sullo schermo il tabellone di gioco, organizzando il programma 
come segue:
OK1. nel main, si assegnino le coordinate (10,10) alla posizione del giocatore, si invochi una funzione di lettura (da sviluppare 
   al punto 2), una di stampa (punto 3) e una di visualizzazione del tabellone (punto 4).
OK2. la funzione di lettura deve leggere il file robots.txt e portarne il contenuto in un opportuno array di strutture. 
   La funzione di lettura deve essere invocata solo una volta, dal main. È vietato leggere più volte il file.
3. la funzione di stampa deve mostrare a video il contenuto dell'array letto al punto 2
4. la funzione di visualizzazione del tabellone deve prendere come parametri le coordinate a cui si trova il giocatore, 
   l'array letto al punto 2 (più eventualmente altri parametri) e deve:
     - creare una matrice 20x20 di caratteri e inizializzare ciascuna cella con uno spazio ' '
     - per ciascun robot nell'array letto al punto 2, deve riportare un asterisco '*' nella cella corrispondente della matrice. 
        Ad esempio, se nel file c'è un robot nella posizione (2,5), si dovrà assegnare un asterisco alla cella di coordinate [2][5]    
        della matrice
     - assegnare alla cella dove si trova il giocatore il carattere punto esclamativo '!'
     - visualizzare sullo schermo la matrice
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define R 7 
#define N 20

typedef struct{
    int x,y;
}crd;

int size=0;

crd scan(char name[11], crd field[]){

    FILE *f;
    f = fopen(name,"r");
    int i=0;

    if(fopen==NULL){
        printf("Errore nella lettura del file...\n ...Programma terminato...\n");
        exit(1);
    }

    while(fscanf(f,"%d %d",&field[i].x,&field[i].y)!=EOF){
        i++;
    }
    size=i;
    printf("size: %d\n",size);

    fclose(f);
    return field[size];
}

crd printR(crd rob[size]){//print dei robot nel campo

    for(int i=0; i<size; i++){
        printf("x: %d\ny: %d\n",rob[i].x,rob[i].y);
    }
}

//funzione visualizza tabellone

int main(){

    crd robots[size];
    //int field[20][20], player[1][1]={0,0};
    scan("robots.txt",robots);
    printR(robots);

    return 0;
}