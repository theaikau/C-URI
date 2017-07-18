#include <stdio.h>
#include <stdlib.h>

void InsereAdj(int **matriz_adj, int rua1, int rua2, int tipo) {
	if(tipo == 1) {
		matriz_adj[rua1-1][rua2-1] = 1;	
	}
	if(tipo == 2) {
		matriz_adj[rua1-1][rua2-1] = 1;
		matriz_adj[rua2-1][rua1-1] = 1;
	}

}

void CompletaAdj(int **matriz_adj, int t) {
	int i, j, k;
	for(i=0; i<t; i++) {
		for(j=0; j<t; j++) {
			if(matriz_adj[i][j]) {
				printf("Adj[%d][%d]\n", i+1, j+1);
				for(k=0; k<t; k++) {
					if(matriz_adj[j][k])
					matriz_adj[i][k] = 1;
				}
			}
		}
	}

}

void ImprimeMatriz (int **matriz_adj, int t) {
	int i, j;
	for(i=0; i<t; i++) {
		for(j=0; j<t; j++) {
			printf("[%d]", matriz_adj[i][j]);
		}
		printf("\n");
	}
}




int Busca(int **matriz_adj, int t, int *visitado,int start) {
	visitado[start] = 1;
	int i;
	for(i=0; i<t; i++) {
		if(matriz_adj[start][i] == 1 && visitado[i] == 0) {
			Busca(matriz_adj, t, visitado, i);
		}
	}

}

int VerificaVetor(int *visitado, int t) {
	int i;
	for(i=0; i<t; i++) {
		if(visitado[i] == 0)
			return 0;
	}
	return 1;
	
}

void VerificaGrafo(int **matriz_adj, int t) {
	int i, j;
	int verificador;
	int *visitado = NULL;
	int *todos = (int*)malloc(sizeof(int)*(t));
	for(j=0; j<t; j++)
			todos[j] = 0;


	for(i=0; i<t; i++) {
		visitado = (int*)malloc(sizeof(int)*(t));
		for(j=0; j<t; j++)
			visitado[j] = 0;

		Busca(matriz_adj, t, visitado, i);
		
		todos[i] = VerificaVetor(visitado, t);
		free(visitado);
	}
	 printf("%d\n", VerificaVetor(todos, t));
}

int main(int argc, char const *argv[]) {
	
	int i, j;

	int num_ruas;
	int linhas;
	int **matriz_adj = NULL;

	int rua1, rua2, tipo;

	fscanf(stdin, "%d", &num_ruas);
	fscanf(stdin, "%d", &linhas);


	while(num_ruas != 0) {
		matriz_adj = (int**)malloc(sizeof(int*)*(num_ruas));

		for(i=0; i<num_ruas; i++) {
			matriz_adj[i] = (int*)malloc(sizeof(int)*(num_ruas));
			for(j=0; j<num_ruas; j++) {
				if(i == j)
					matriz_adj[i][j] = 1;
				else
					matriz_adj[i][j] = 0;
			}
		}
		
		for(i=0; i<linhas; i++) {
			fscanf(stdin, "%d %d %d", &rua1, &rua2, &tipo);
			InsereAdj(matriz_adj, rua1, rua2, tipo);
		}

		VerificaGrafo(matriz_adj, num_ruas);

		for(i=0; i<num_ruas; i++) {
			free(matriz_adj[i]);
		}
		free(matriz_adj);

		fscanf(stdin, "%d", &num_ruas);
		fscanf(stdin, "%d", &linhas);
	}
	
	return 0;
}