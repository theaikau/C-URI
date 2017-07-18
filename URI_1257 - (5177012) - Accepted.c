#include <stdio.h>
#include <stdlib.h>

#define TAM_STRING 50

int TamanhoString (char *String) {
    int TamanhoString = 0;
    int i = 0;
    while(String[i] != '\0') {
        TamanhoString++;
        i++;
    }
    return TamanhoString;
}

int main(int argc, char const *argv[]) {

    int i = 0, j = 0, k = 0;
    int Soma = 0;
    int nTestes = 0;
    int nStrings = 0;
    char String[TAM_STRING];

    fscanf(stdin, "%d", &nTestes);

    for(i=0; i<nTestes; i++) {
        fscanf(stdin, "%d", &nStrings);
        Soma = 0;

        for(j=0; j<nStrings; j++) {
            fscanf(stdin, "%s", String);
            //printf("String: %s | [%d] \n", String, TamanhoString(String));

            for(k=0; k<TamanhoString(String); k++) {
                Soma += String[k]%65 + j + k;
            }
        }

        printf("%d\n", Soma);
    }

    return 0;
}
