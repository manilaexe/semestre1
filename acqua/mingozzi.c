/*
Svolto solo il punto 1
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
    char sdr[15];
    int x,y; //partenza a (0,0)
}id;

int lettura(id a[100]){ //legge idranti.bin + array di strutture + mostra array

    int i=0;
    int size;
    FILE *f;
    f=fopen("idranti.bin","rb");

    if(f==NULL){
        perror("Il file non esiste, programma terminato...");
        exit(1);
    }

    while(fread(&a[i],sizeof(id),1,f)>0){
        a[i].x=a[i].x;
        a[i].y=a[i].y;
        strcpy(a[i].sdr,a[i].sdr);
        i++;
    }

    size=i;

    for(int i=0; i<size; i++){
        printf("(%d , %d): %s\n",a[i].x,a[i].y,a[i].sdr);
    }

    return size;
}

int distanza(int x, int y){//fornisce la distanza euclidea

    int dis;
    dis=sqrt(pow((double)x,2)+pow((double)y,2));
    return dis;

}

void intervento(id a[100], int size){ //calcola la squadra che arriva alla massima distranza 
    //deve incovare la distanza euclidea
    int max=0;
    id mag;

    for(int i=0; i<size; i++){
        if(distanza(a[i].x,a[i].y)>max){
            max=distanza(a[i].x,a[i].y);
            mag.x=a[i].x;
            mag.y=a[i].y;
            strcpy(mag.sdr,a[i].sdr);
        }
    }

    printf("La squadra che deve raggiungere la maggior distanza e`: %s\n",mag.sdr);
}




int main(){

    id idranti[100];
    int size;

    size=lettura(idranti);
    intervento(idranti,size);
    return 0;
}