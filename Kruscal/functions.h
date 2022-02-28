#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aresta{
    int vert_u;
    int vert_v; 
    int peso;
}aresta;

int impriSol (aresta *aux, int n_ver, int imp, char nome_saida[]);

void Union(int find_u, int find_v, int pai[], int rank[]);

int find(int vert, int pai[], int n_ver);

void kruskal(aresta *arestas, int n_ver, int n_ares, int imp, char nome_saida[]);

void quicksort(aresta arestas[], int began, int end);

#endif