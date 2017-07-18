#include <stdio.h>
#include <stdlib.h>

int VerificaRepetidos (char *num) {
    int verificadores[10];
    char digito;

    int i = 0;

    for(i=0; i<10; i++) verificadores[i] = 0;

    i = 0;

    while(num[i] != '\0') {
        digito = num[i];
        if(verificadores[atoi(&digito)] == 0) verificadores[atoi(&digito)] = 1;
        else return 0;
        i++;
    }

    return 1;
}

void VerificaPossibilidades (int x1, int x2) {
    char num[5];
    int i;
    int soma = 0;


    for(i=x1; i<=x2; i++) {
        sprintf(num, "%d", i);
        soma += VerificaRepetidos(num);
    }
    
    printf("%d\n", soma);
}

int main(int argc, char const *argv[]) {
    int x1;
    int x2;
    int ciclo = 1;

    while(ciclo) {
        if(fscanf(stdin, "%d", &x1) != EOF) {
            if(fscanf(stdin, "%d", &x2) != EOF) {
                
                VerificaPossibilidades (x1, x2);
            }
            else {
                ciclo =  0;
            }
        }
        else {
            ciclo =  0;
        }
    }



    return 0;
}