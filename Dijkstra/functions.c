#include "functions.h"


int busca(int n_ver, int matriz[][n_ver], int v0, No infos[]){
    int menor = INT_MAX, index;

    for(int i = 0; i < n_ver; i++){
        if (matriz[v0-1][i] != 0 && infos[i+1].distancia > infos[v0].distancia + matriz[v0-1][i]){
            infos[i+1].distancia = infos[v0].distancia + matriz[v0-1][i];
            infos[i+1].anterior = v0;

            if(infos[i+1].distancia < menor){
                index = i + 1;
                menor = infos[i+1].distancia;
            }
        }
    }
    return index;
}

void dijkstra(int n_ver, int n_ares, int matriz[][n_ver], int v0, int imp, char nome_saida[]){
    
    No infos[n_ver + 1];
    for(int i = 1; i < n_ver + 1; i++){
        infos[i].visitado = 0;
        infos[i].distancia = INT_MAX;
        infos[i].anterior = -1;
    }

    int inicial = v0;
    infos[v0].distancia = 0;

    for(int j = 1; j < n_ver + 1; j++){

        for(int i = 1; i < n_ver + 1; i++){
            infos[v0].visitado = 1;
            v0 = busca(n_ver,matriz, v0, infos);
        }

        int menor = INT_MAX;

        for(int i = 1; i < n_ver + 1; i++){
            if(infos[i].distancia < menor && infos[i].visitado == 0){
                v0 = i;
                menor = infos[i].distancia;
            }
        }
    }

    if (imp != 0){
        impri_sol(n_ver, inicial, infos, imp, nome_saida);
    }

    
}

void impri_sol(int n_ver, int inicial, No infos[], int imp, char nome_saida[]){
    
    if(imp == 1){
        for(int i = 1; i < n_ver + 1; i++){
            printf("%d -> %d = %d\n", inicial, i, infos[i].distancia == INT_MAX?-1:infos[i].distancia);
        }
    }
    else{
        FILE *pont_saida;

        pont_saida = fopen(nome_saida, "w");

        fclose(pont_saida);

        pont_saida = fopen(nome_saida, "a");

        for(int i = 1; i < n_ver + 1; i++){
            fprintf(pont_saida, "%d -> %d = %d\n", inicial, i, infos[i].distancia == INT_MAX?-1:infos[i].distancia);
        }

        fclose(pont_saida);
    }
}


