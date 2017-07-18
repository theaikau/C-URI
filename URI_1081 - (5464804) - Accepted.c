#include <stdio.h>
#include <stdlib.h>

#define maxV 20 // Máximo de vértices.
static int desconhecido[maxV]; // Vértice que já foi "encontrado", para evitar repetição na saída.

// Estrutura do Grafo do tipo matriz de adjacências. 
typedef struct GRAFO {
	int **matriz_adj;
	int V;
	int A;
}GRAFO;

// Imprime a quantidade de "espaços em branco" de acordo com a quantidade
// passada por parâmetro.
void ImprimeSpaces (int vezes) {
	
	int i = 0;
	while(i < vezes) {
		printf("  ");
		i++;	
	}
}

// Inicializa o Grafo.
void InicalizaMatriz (GRAFO *G) {
	
	// Criação uma matriz de adjacências nula (sem ligação entre os vértices).
	int i, j;
	for(i=0; i<G->V; i++) {
		for(j=0; j<G->V; j++) {
			G->matriz_adj[i][j] = 0;
		}
	}

	// Leitura das adjacências e inserção da adjacência na matriz. 
	int v1, v2;
	i = 0;
	while(i < G->A) {
		fscanf(stdin, "%d", &v1);
		fscanf(stdin, "%d", &v2);
		G->matriz_adj[v1][v2] = 1;
		i++;
	}
	

}

// Verifica se o vértice de um ID específico não tem adjacências.
// Retorna 0 se houver, 1 caso contrário.
short VerticeVazio(GRAFO *G, int id) {
	
	int i;

	// Percorre as adjacências do vértice.
	for(i=0; i<G->V; i++) {
		if(G->matriz_adj[id][i] == 1) return 0;
	}
	return 1;
}

// Imprime a matriz de adjacências.
void ImprimeMatriz(GRAFO *G) {
	int i, j;
	for(i=0; i<G->V; i++) {
		for(j=0; j<G->V; j++) {
			printf("[%d] ", G->matriz_adj[i][j]);
		}
		printf("\n");
	}
}

// BUSCA EM PROFUNDIDADE NO GRAFO (DFS)
void BuscaProfundidade (GRAFO *G, int indice, int spaces) {
	int i;

	spaces++;

	if(desconhecido[indice]) {
		desconhecido[indice] = 0;
		for(i=0; i<G->V; i++) {
			if(G->matriz_adj[indice][i]) {
				ImprimeSpaces(spaces);
				if(desconhecido[i])
					printf("%d-%d pathR(G,%d)\n", indice, i, i);
				else
					printf("%d-%d\n", indice, i);
				BuscaProfundidade(G, i, spaces);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	
	int i = 0;
	int j = 0;
	int n = 1;

	int num_testes; // Quantidade de testes a serem realizados. 

	fscanf(stdin, "%d", &num_testes);
	GRAFO G;

	while(j < num_testes) {

		// Tamanho da Matriz de Adjacências.
		fscanf(stdin, "%d", &G.V);
		fscanf(stdin, "%d", &G.A);

		// Aloca a Matriz.
		G.matriz_adj = (int**)malloc(sizeof(int*)*(G.V));
		for(i=0; i<G.V; i++)
			G.matriz_adj[i] = (int*)malloc(sizeof(int)*(G.V));

		// Cria o Grafo.
		InicalizaMatriz(&G);

		// Marca todos os vértices como "não descobertos na busca".
		for(i=0; i<maxV; i++)
			desconhecido[i] = 1;

		// Processamento do Caso.
		printf("Caso %d:\n", n);
		for(i=0; i<G.V; i++) {
			if(desconhecido[i] && !VerticeVazio(&G, i) && i!=0)
					printf("\n");
			if(desconhecido[i]) {
				BuscaProfundidade(&G, i, 0);
				
			}

		}

		// Libera memória alocada para a matriz.
		for(i=0; i<G.V; i++)
			free(G.matriz_adj[i]);
		free(G.matriz_adj);
		
		j++;
		n++;
		
		printf("\n");
	}

	return 0;
}
