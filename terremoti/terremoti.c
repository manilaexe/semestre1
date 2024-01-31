#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    float lat, lon, prf, mag;
    char pos[60];

} terr;

int lettura(terr ret[100], int *size){ //legge dal file di testo e riporta in un array

    terr let[100]; //array di appoggio
    int i=0;
    FILE *f;
    f=fopen("terremoti.txt","r");
    
    if(f==NULL){
        printf("File inesistente... Programma terminato\n");
        exit(1);
    }

    while(fscanf(f, "%f %f %f %f %s", &let[i].lat, &let[i].lon, &let[i].prf, &let[i].mag, let[i].pos)!=EOF){ //leggo un terremoto alla volta e lo salvo in un array
       
        ret[i].lat=let[i].lat;
        ret[i].lon=let[i].lon;
        ret[i].prf=let[i].prf;
        ret[i].mag=let[i].mag;
        strcpy(ret[i].pos,let[i].pos);
        i++;
    }   

    *size=i;
        
    fclose(f);

}
void stampa(terr t[100], int size){ //mostra il contenuto a video

    for(int i=0; i<size; i++){

        printf("%f %f %.1f %.1f %s\n",t[i].lat, t[i].lon, t[i].prf, t[i].mag, t[i].pos);
    }
}

void visual(terr t[100], int size){ //terremoti ad alta magnitudine

    for(int i=0; i<size; i++){
        if (t[i].mag>=5){
            printf("@%f %f %.1f %.1f %s@\n",t[i].lat, t[i].lon, t[i].prf, t[i].mag, t[i].pos);
        }
    }

}

int main (){

    terr terremoti[100];
    int l;
    lettura(terremoti,&l);
    printf("\n---ELENCO DI TUTTI I TERREMOTI---\n");
    stampa(terremoti,l);
    printf("-------------------------------------\n\n\n\n\n\n");
    printf("---ELENCO DEI TERREMOTI CON MAGNITUDO >=5---\n");
    visual(terremoti,l);
    printf("-------------------------------------\n\n\n\n\n\n"); 
    

    printf("Programma terminato...\n");
    return 0;
}






















