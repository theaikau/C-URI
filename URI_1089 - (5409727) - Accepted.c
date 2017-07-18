#include <stdio.h>
#include <stdlib.h>

void RegistraAmostras(int *vetor_amostras, int amostras_no_loop) {
    int i;
    for(i=0; i<amostras_no_loop; i++) fscanf(stdin, "%d", &vetor_amostras[i]);
}

int main(int argc, char const *argv[]) {
    int i = 0;

    int amostras_no_loop;
    int picos;
    int subindo; int descendo;

    int *vetor_amostras = NULL;

    while(fscanf(stdin, "%d", &amostras_no_loop) && amostras_no_loop != 0) {
        vetor_amostras = (int*)malloc(sizeof(int)*(amostras_no_loop+1));
        RegistraAmostras(vetor_amostras, amostras_no_loop);

        subindo = 0;
        descendo = 0;
        picos = 0;

        if(vetor_amostras[amostras_no_loop-1]<vetor_amostras[0]) subindo = 1;
        else descendo = 1;

        vetor_amostras[amostras_no_loop] = vetor_amostras[0];

        for(i=1; i<=amostras_no_loop; i++) {
            if(vetor_amostras[i-1]<vetor_amostras[i] && descendo) {
                picos++;
                descendo = 0; subindo = 1;
            }
            else if(vetor_amostras[i-1]>vetor_amostras[i] && subindo) {
                picos++;
                descendo = 1; subindo = 0;
            }
        }

        printf("%d\n", picos);
        free(vetor_amostras);

    }


    return 0;
}