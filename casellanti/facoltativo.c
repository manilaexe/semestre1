//main e funzioni punto 2
/*
Si supponga ora che il numero di casellanti necessari non sia uguale in tutte le fasce orarie, ma
che dipenda dall orario. In particolare, il file binario casellanti.bin contiene una sequenza di 24
valori di tipo unsigned char; il primo elemento rappresenta il numero di casellanti necessari alle
ore 0, il secondo alle ore 1, ecc.OKOK

Si modifiichi il programma in modo che visualizzi gli orari in cui il numero di casellanti è insufficiente, 
considerando come numero minimo richiesto quello indicato nel file casellanti.bin. OKOK

Il programma deve funzionare correttamente anche nel caso in cui un turno inizi in un giorno e
termini il giorno successivo. NON HO CAPITO MA OK

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"

int scancas(char n[24]){ //punto 2; Legge casellanti.bin + array di char e visualizza

    FILE *c;
    int size;
    int j=0;

    c=fopen("casellanti.bin","rb");
    if(c==NULL){
        printf("File inesistente... Programma termianto\n");
        exit(-1);
    }

    while(j<=23){ //array con i casellanti necessari
        fread(&n[j], sizeof(char), 1, c);
        n[j]=n[j];
        j++;
    }

    for(int i=0; i<j; i++){
        printf("%d \n",n[i]); //immagino abbia fatto il cast da solo perche` se metto %c non funziona piu` niente

    }
    
    fclose(c);
    size=j;
}

void insuff(casellanti t[100], int size, char n[24]){
    
    int check;

    for(int i=0; i<=23; i++){
        check=presenti(t,i,size);
        if((char)check<n[i]){
            printf("Ad ore: %d i casellanti sono insufficienti(%d)\n",i,check);
        }
    }


}

int main(){

    casellanti cas[100];
    char nec[24];
    int n;
    scancas(nec);
    n=scan(cas);
    insuff(cas,n,nec);
    
    return 0;
}