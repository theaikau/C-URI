#include <stdio.h>
#include <stdlib.h>

int compara (const void * x, const void * y) {
    return (*(int*)y - *(int*)x);
}
 
int main ( ) {
    int T, N, C, M;
    int i;
    int energia;
    int andares[100000];
 
    fscanf(stdin, "%d", &T);
 
    while (T--) {
 
        fscanf(stdin, "%d", &N);
        fscanf(stdin, "%d", &C);
        fscanf(stdin, "%d", &M);
       
        for (i=0; i<M; i++)
            fscanf(stdin, "%d", &andares[i]);
        
        qsort(andares, M, sizeof(int), compara);
        
        energia = 0;
 
        for( i=0; i<M; i+= C)
            energia += andares[i] * 2;
 
        printf ("%d\n", energia);
    }
 
    return 0;
}