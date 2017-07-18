#include <stdio.h>
 
int main() {

	// Declaração.
    int a;
    int b;

    // Leitura.
    fscanf(stdin, "%d", &a);
    fscanf(stdin, "%d", &b);

    // Operação de soma e saída.
    printf("X = %d\n", a+b);
 
    return 0;
}