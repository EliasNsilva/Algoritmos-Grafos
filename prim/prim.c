#include "functions.h"

int main(int argc, char *argv[ ])
{
    char string[100], string2[5], nome_saida[100];
    int n_ver, n_ares, x , y, a; 
    int v0 = 1, imp = 0;
    char z;

    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], "-h") == 0){
            printf("-o <arquivo> : redireciona a saida para o arquivo\n-f <arquivo> : indica o arquivo que contém o grafo de entrada\n-s : mostra a solução em ordem crescente\n-i : vértice inicial dependendo do algoritmo\n");
            return 0;
        }
        else if(strcmp(argv[i], "-f") == 0){
            strcpy(string, argv[i + 1]);
        } 
        else if(strcmp(argv[i], "-i") == 0){
           v0 = atoi(argv[i+1]);
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

    int matriz[n_ver+1][n_ver+1];

    for(int i = 0; i <= n_ver; i++) {
        for(int j = 0; j <= n_ver; j++ ){
            matriz[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n_ares; i++ ){
        fscanf(pont_arq, "%d %d%c", &x, &y, &z);
        if (z == ' '){
            fscanf(pont_arq, "%d", &a);
        }
        else {
            a = 1;
        }
        matriz[x][y] = a;
        matriz[y][x] = a;
    }
    
    fclose(pont_arq);

    FILE *pont_saida;

    int total = prim(n_ver, matriz, v0, imp, nome_saida, pont_saida);
    
    printf("\nCusto total= %d\n", total);
    
    return 0;
}
