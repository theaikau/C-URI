#include <stdio.h>
#include <stdlib.h>

#define ASSINATURA 1000000
#define PAINEL 300000

typedef struct Assinatura {
    int *Elementos;
    int Tamanho;
}Assinatura;

typedef struct Painel {
    int *Elementos;
    int Tamanho;
}Painel;

void RegistraAssinatura (Assinatura *X) {
    int i = 0;

    for(i=0; i<ASSINATURA; i++)
        X->Elementos[i] = 0;

    i = 0;
    char NUM = fgetc(stdin);
    while (NUM != '\n' && i < ASSINATURA) {
        X->Elementos[i] = atoi(&NUM);
        NUM = fgetc(stdin);
        i++;
    }
    X->Tamanho = i;

}

void RegistraPainel (Painel *Y) {
    int i = 0;

    for(i=0; i<PAINEL; i++)
        Y->Elementos[i] = 0;

    i = 0;
    char NUM = fgetc(stdin);
    while (NUM != '\n' && i < PAINEL) {
        Y->Elementos[i] = atoi(&NUM);
        NUM = fgetc(stdin);
        i++;
    }
    Y->Tamanho = i;

}

int AssinaturaVerdadeira (Assinatura *X) {
    int i = 0;
    int Verificador = 0;
    for(i=0; i<ASSINATURA; i++) {
        if(X->Elementos[i] != 0) return 1;
    }
    return 0;
}

int VerificaPainel (Assinatura *X, Painel *Y) {
    int i=0, j=0, k=0;

    if(X->Tamanho > Y->Tamanho) return 0;

    for(i=0; i<PAINEL; i++) {
        j++;
        if(Y->Elementos[i] == X->Elementos[i]) {
            k++;
            i++;
            if(k == X->Tamanho)
                return 1;
        }
        else {
            i = i + j;
            j = 0;
        }
    }
    return 0;

}

void preKMP(int *X, int Tamanho, int TabelaKMP[]) {
   int i, j;

   i = 0;
   j = TabelaKMP[0] = -1;
   while (i < Tamanho) {
      while (j > -1 && X[i] != X[j])
         j = TabelaKMP[j];
      i++;
      j++;
      if (X[i] == X[j])
         TabelaKMP[i] = TabelaKMP[j];
      else
         TabelaKMP[i] = j;
   }
}

int KMP(Assinatura *X, Painel *Y) {
   int i, j, TabelaKMP[X->Tamanho];

   preKMP(X->Elementos, X->Tamanho, TabelaKMP);

   i = j = 0;
   while (j < Y->Tamanho) {
      while (i > -1 && X->Elementos[i] != Y->Elementos[j])
         i = TabelaKMP[i];
      i++;
      j++;
      if (i >= X->Tamanho) {
         return 1;
         i = TabelaKMP[i];
      }
   }
   return 0;
}


void ImprimeResultado (int Verificador, int nPainel) {
    printf("Instancia %d\n", nPainel);
    if(Verificador)
        printf("verdadeira\n");
    else
        printf("falsa\n");

}

int main(int argc, char const *argv[]) {

    int i = 0;
    int nPainel = 1;
    int ResultadoBusca = 0;

    Assinatura X;
    X.Elementos = malloc(sizeof(int)*(ASSINATURA+1));
    Painel Y;
    Y.Elementos = malloc(sizeof(int)*(PAINEL+1));

    RegistraAssinatura(&X);

    while(AssinaturaVerdadeira(&X)) {
        if(nPainel != 1) printf("\n");
        RegistraPainel(&Y);
        ResultadoBusca = KMP(&X, &Y);
        ImprimeResultado(ResultadoBusca, nPainel);
        RegistraAssinatura(&X);
        nPainel++;
    }
    free(X.Elementos);
    free(Y.Elementos);

    return 0;
}
