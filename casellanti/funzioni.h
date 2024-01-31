typedef struct casellanti{
    char cognome[20];
    int start, end;
}casellanti;

int scan(casellanti t[100]);
int presenti(casellanti t[100], int ora, int size);
