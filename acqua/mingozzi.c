/*
In caso di contaminazione dell'acqua dell'acquedotto, si devono aprire gli idranti della città, 
in modo che l'inquinante venga disperso velocemente. Per effettuare questo, è necessario mandare delle squadre di tecnici ad aprire gli idranti. 
Gli idranti sono al più 100. Il piano di svuotamento è salvato in un file binario  idranti.bin e contiene la sequenza di idranti da aprire. Per ciascun idrante, 
esso contiene:

squadra (stringa contenente al massimo 15 caratteri, compreso il terminatore): nome della squadra
x,y (di tipo int): coordinate dell'idrante nel piano cartesiano OK
Sapendo che il punto di partenza è alle coordinate (0,0), si desidera sapere qual è la squadra che deve raggiungere il punto più lontano dall'origine, 
come distanza euclidea.

1. nel main, si invochi una funzione di lettura (da implementare al punto 2) ed una di calcolo della squadra che arriva alla distanza massima (punto 3), 
    poi si visualizzi (nel main) il nome della squadra che arriva alla distanza massima. OK

2. si implementi la funzione (o procedura) di lettura. Tale funzione deve leggere il file idranti.bin e portarne il contenuto in un opportuno array di strutture. 
    Si mostri a video l'array. OK

3. Si implementi la funzione (o procedura) che calcola la squadra che arriva alla distanza massima dall'origine degli assi. Tale funzione deve ricevere come parametro 
    l'array letto al punto 2 (più eventualmente altri parametri) e deve fornire al main il nome della squadra che ha raggiunto il punto più lontano dall'origine. 
    Per fare questo, questa funzione deve invocare una funzione di calcolo della distanza euclidea (da implementare al punto 4)

4. Si implementi la funzione di calcolo della distanza euclidea di un idrante dall'origine degli assi. Tale funzione deve prendere come parametro una struttura 
    che rappresenta un idrante e fornire la distanza euclidea dell'idrante dall'origine degli assi.


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