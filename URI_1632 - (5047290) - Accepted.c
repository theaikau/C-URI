#include <stdio.h>

#define TAM_MAX 16

int main() {
 
    int i = 0, j = 0;
    
    // Zera os elementos do vetor da senha.
    char Senha[TAM_MAX];
    for(i=0; i<TAM_MAX; i++)
        Senha[i] = 0;
    
    // Zera os elementos do vetor de fatores.
    int Fatores[TAM_MAX];
    for(i=0; i<TAM_MAX; i++)
        Fatores[i] = 0;

    int Variantes = 0;
    int QntSenhas = 0;

    fscanf(stdin, "%d", &QntSenhas);

    for(i=0; i<QntSenhas; i++) {
        fscanf(stdin, "%s", Senha); // Lê a senha.
        
        // Atribui os pesos de cada letra na senha ao vetor de fatores.
        for(j=0; j<TAM_MAX; j++) {
            if(Senha[j] == 'A' || Senha[j] == 'a' )
                Fatores[j] = 3;
            else if(Senha[j] == 'E' || Senha[j] == 'e' )
                    Fatores[j] = 3;
            else if(Senha[j] == 'I' || Senha[j] == 'i' )
                    Fatores[j] = 3;
            else if(Senha[j] == 'O' || Senha[j] == 'o' )
                    Fatores[j] = 3;
            else if(Senha[j] == 'S' || Senha[j] == 's' )
                    Fatores[j] = 3;
            else if (Senha[j] > 64 && Senha[j] < 91)
                    Fatores[j] = 2;
            else if(Senha[j] > 96 && Senha[j] < 123)
                    Fatores[j] = 2;
            else
                Fatores[j] = 0;
        }

        // Multiplica os fatores no vetor para achar a quantidade de variações.
        Variantes = Fatores[0];
        for(j=1; j<TAM_MAX; j++)
            if(Fatores[j] != 0) // Evita os zeros na multiplicação.
                Variantes = Variantes*Fatores[j];
        printf("%d\n", Variantes);
    }
 
    return 0;
}