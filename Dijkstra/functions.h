#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct {
    int visitado;
    int distancia;
    int anterior;
}No;

int busca(int n_ver, int matriz[][n_ver], int v0, No infos[]);

void dijkstra(int n_ver, int n_ares, int matriz[][n_ver], int v0, int imp, char nome_saida[]);

void impri_sol(int n_ver, int inicial, No infos[], int imp, char nome_saida[]);

#endif