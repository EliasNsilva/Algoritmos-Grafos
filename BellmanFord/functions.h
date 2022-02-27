#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct aresta{
    int vert_u;
    int vert_v;
    int peso;
}aresta;

void imprSol (int vert_u, int vert_v, int ant[]);

void gravarSol (int vert_u, int vert_v, int ant[], FILE *pont_saida, char nome_saida[]);

int bellmanFord(int n_ver, int distancia[], int ant[], int n_ares, aresta *arestas, int v0, int vf, int imp, char nome_saida[]);


#endif