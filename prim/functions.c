#include "functions.h"

int prim(int n_ver, int matriz[][n_ver+1], int v0, int imp, char nome_saida[], FILE *pont_saida){

    int aux, a_i, b_j;
    int contador = 1,  custo = 0;

    int visitados[n_ver + 1];

    for (int i = 0; i <= n_ver; i++){
        visitados[i] = 0;
    }

    visitados[v0] = 1;

    while(contador < n_ver)
    {
        aux = INT_MAX;

        for(int i = 1; i <= n_ver; i++)
        {
            for(int j = 1; j <= n_ver; j++)
            {
                if(matriz[i][j] < aux)
                {

                    if(visitados[i] != 0)
                    {
                        aux=matriz[i][j];
                        a_i = i;
                        b_j = j;
                    }
                }
            }
        }

        if(visitados[b_j] == 0)
        {
            if (imp == 1){
                printf("\n(%d, %d) peso =%d\n", a_i, b_j, aux);
            }
            else if (imp == 2){
                pont_saida = fopen(nome_saida, "a");

                fprintf(pont_saida,"\n(%d, %d) peso =%d\n", a_i, b_j, aux);

                fclose(pont_saida);
            }

            custo = custo + aux;
            contador++;
        }

        visitados[b_j] = 1;
        matriz[a_i][b_j] = INT_MAX;
        matriz[b_j][a_i] = INT_MAX; 
    }
    return custo;
}
