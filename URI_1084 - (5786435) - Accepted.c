#include <stdio.h>
#include <stdlib.h>

#define tamanhoMax 100000
#define ganhoVazio -1



int main(int argc, char const *argv[]) {

    char ganho[tamanhoMax], num[tamanhoMax];
	
    int N, digitos, topo;
    char aux;
    int i;

	while ( scanf("%d %d", &N, &digitos), (N || digitos)) {
        
        topo = ganhoVazio;
        scanf("%s", num);
        for(i = 0; i < N; i++)
        {
            aux = num[i];
            while ( digitos > 0 && topo != ganhoVazio && ganho[topo] < aux )
                --topo, --digitos;
            ganho[++topo] = aux;
        }
        topo -= digitos;
        ganho[topo+1] = 0;

        printf("%s\n", ganho);
    }

    return 0;
}