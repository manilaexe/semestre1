#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//A POSTO

typedef struct{
    char cognome[20];
    int start, end;
}casellanti;

int scan(casellanti t[100]){ //punto 2; Legge casello.bin + array di struttore e visualizza

    FILE *c;
    int size;
    int j=0;
    c=fopen("casello.bin","rb");
    if(c==NULL){
        printf("File inesistente... Programma termianto\n");
        exit(-1);
    }

    while(fread(&t[j], sizeof(casellanti), 1, c)>0){
        strcpy(t[j].cognome,t[j].cognome);
        t[j].start=t[j].start;
        t[j].end=t[j].end;
        j++;
    }

    for(int i=0; i<j; i++){
        printf("%s %d %d\n",t[i].cognome, t[i].start, t[i].end);
    }
    
    fclose(c);
    size=j;
    return size;
}

int presenti(casellanti t[100], int ora, int size){ //

    int s=0; //casellanti in servizio
    int i=0;

    for(i=0; i<size; i++){
        if(ora>=t[i].start && ora<t[i].end){
            s++;
        }
    }
    return s;
}

int few(casellanti t[100], int size){ //punto 3: insufficienti casellanti (<4)
    
    int check;
    for(int i=0; i<=23; i++){
        check=presenti(t,i,size);
        if(check<4){
            printf("Ad ore: %d i casellanti sono insufficienti(%d)\n",i,check);
        }
    }

}

int main(){

    casellanti cas[100];
    int n;   

    n=scan(cas);
    few(cas,n);

    return 0;
}




