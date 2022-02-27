#include "functions.h"

void imprSol (int vert_u, int vert_v, int ant[]){
    if (vert_u==vert_v){
        printf("%d ", vert_u);
    }else if (ant[vert_v]==-1){
        printf("Não existe caminho de %d para %d\n", vert_u, vert_v);
    }else{
        imprSol(vert_u, ant[vert_v], ant);
        printf("%d ", vert_v);
    }
}

void gravarSol (int vert_u, int vert_v, int ant[], FILE *pont_saida, char nome_saida[]){
    if (vert_u==vert_v){
        fprintf(pont_saida,"%d ", vert_u);
    }else if (ant[vert_v]==-1){
        fprintf(pont_saida,"Não existe caminho de %d para %d\n", vert_u, vert_v);
    }else{
        gravarSol(vert_u, ant[vert_v], ant, pont_saida, nome_saida);
        fprintf(pont_saida, "%d ", vert_v);
    }
}


int bellmanFord(int n_ver, int distancia[], int ant[], int n_ares, aresta *arestas, int v0, int vf, int imp, char nome_saida[]){
 
    for(int i = 0; i < n_ver - 1; i++){
        for (int j=0; j<n_ares; j++){
            if (distancia[arestas[j+1].vert_v] > distancia[arestas[j+1].vert_u] + arestas[j+1].peso){
                distancia[arestas[j+1].vert_v] = distancia[arestas[j+1].vert_u] + arestas[j+1].peso;
                ant[arestas[j+1].vert_v] = arestas[j+1].vert_u;
            }
        }
    }

    for(int i = 0; i < n_ver - 1; i++){
        for (int j=0; j<n_ares; j++){
            if (distancia[arestas[j+1].vert_v] > distancia[arestas[j+1].vert_u] + arestas[j+1].peso){
                return 0;
            }
        }
    }

    if(imp == 1){
        imprSol(v0, vf, ant);
        printf("\n");
    }
    else if(imp == 2){
        FILE *pont_saida;

        pont_saida = fopen(nome_saida, "w");

        fclose(pont_saida);

        pont_saida = fopen(nome_saida, "a");

        gravarSol(v0, vf, ant, pont_saida, nome_saida);
    }

    printf("Custo do caminho: %d\n", distancia[vf]);
}
