#include "functions.h"

int main(int argc, char *argv[ ]){

    char string[100], string2[5], nome_saida[100];
    int n_ver, n_ares, x , y, a, v0, vf;
    int imp = 0;
    char z;

    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-h") == 0){
            printf("-o <arquivo> : redireciona a saida para o arquivo\n-f <arquivo> : indica o arquivo que contém o grafo de entrada\n-s : mostra a solução em ordem crescente\n-i : vértice inicial dependendo do algoritmo\n-l : vértice final dependendo do algoritmo\n");
            return 0;
        }
        else if(strcmp(argv[i], "-f") == 0){
            strcpy(string, argv[i + 1]);
        } 
        else if(strcmp(argv[i], "-i") == 0){
           v0 = atoi(argv[i+1]);
        } 
        else if(strcmp(argv[i], "-l") == 0){
           vf = atoi(argv[i+1]);
        } 
        else if(strcmp(argv[i], "-s") == 0){
            imp = 1;
        }
        else if(strcmp(argv[i], "-o") == 0){
            strcpy(nome_saida, argv[i + 1]);
            imp = 2;
        }
    }

    FILE *pont_arq;

    pont_arq = fopen(string, "r");

    fscanf(pont_arq, "%d %d", &n_ver, &n_ares);

    aresta arestas[n_ares];

    for(int i = 1; i <= n_ares; i++ ){
        fscanf(pont_arq, "%d %d%c", &x, &y, &z);
        if (z == ' '){
            fscanf(pont_arq, "%d", &a);
        }
        else {
            a = 1;
        }
        arestas[i].vert_u = x;
        arestas[i].vert_v = y;
        arestas[i].peso = a;
    }
    fclose(pont_arq);

    int distancia[n_ver+1], ant[n_ver+1];

    for (int i = 1; i <= n_ver; i++){
        distancia[i] = INT_MAX;
        ant[i] = -1;
    }

    distancia[v0] = 0;

    if (bellmanFord(n_ver, distancia, ant, n_ares, arestas, v0, vf, imp, nome_saida) == 0){
        printf("O grafo contem um ciclo negativo\n");
    }
    
    return 0;
}