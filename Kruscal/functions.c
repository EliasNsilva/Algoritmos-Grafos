#include "functions.h"

int impriSol (aresta *aux, int n_ver, int imp, char nome_saida[]){
    int custo=0;

    if (imp == 1){
        for(int i = 0; i < n_ver; i++){
            printf("(%d, %d) ", aux[i].vert_u, aux[i].vert_v);
            custo += aux[i].peso;
        }
    }
    else if (imp == 2){
        FILE *pont_saida;

        pont_saida = fopen(nome_saida, "w");

        fclose(pont_saida);

        pont_saida = fopen(nome_saida, "a");

        for(int i = 0; i < n_ver; i++){
            fprintf(pont_saida,"(%d, %d) ", aux[i].vert_u, aux[i].vert_v);
            custo += aux[i].peso;
        }

        fclose(pont_saida);
    }

    return custo;

}

void Union(int find_u, int find_v, int pai[], int rank[]){

    if (rank[find_u] >= rank[find_v]){ 
        pai[find_v] = find_u;

        if (rank[find_u] == rank[find_v]){
           rank[find_u]++;
        }
    }
    else{
        pai[find_u] = find_v;
    }
}

int find(int vert, int pai[], int n_ver){
    int raiz=vert, no=vert, predecessor;

    while(raiz != pai[vert]){
        raiz = pai[vert];
    }
    while(no != no){
        predecessor = pai[no];
        pai[no] = raiz;
        no = predecessor;
    }
    return raiz;
}

void kruskal(aresta *arestas, int n_ver, int n_ares, int imp, char nome_saida[]){

    int j=0, u, v, find_u, find_v, rank[n_ver], pai[n_ver];
    aresta aux[n_ver];

    for (int i = 1; i < n_ver + 1; i++){
        pai[i] = i;
        rank[i] = 0;
    }
    for (int i = 1; i <= n_ares; i++){
        if (n_ver-1 == j){
            break;
        }
        else{
            u = arestas[i].vert_u;
            v = arestas[i].vert_v;

            find_u = find(u, pai, n_ver);
            find_v = find(v, pai, n_ver);

            if (find_u != find_v){
                aux[j] = arestas[i];
                Union(find_u, find_v, pai, rank);
                j++;
            }
        }
    }

    int custo = impriSol(aux, n_ver-1, imp, nome_saida);
    printf("\nCusto do caminho: %d\n", custo);

}

void quicksort(aresta arestas[], int began, int end){
	int i, j;
    aresta pivo, aux;
	i = began;
	j = end-1;
	pivo = arestas[(began + end) / 2];
	while(i <= j)
	{
		while(arestas[i].peso < pivo.peso && i < end)
		{
			i++;
		}
		while(arestas[j].peso > pivo.peso && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = arestas[i];
			arestas[i] = arestas[j];
			arestas[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quicksort(arestas, began, j+1);
	if(i < end)
		quicksort(arestas, i, end);
}