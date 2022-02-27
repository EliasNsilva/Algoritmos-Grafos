# Algoritmos de Grafos

## Formado do comando para execução 

Dentro da pasta do algoritmo desejado:
```
make; ./algoritmo -flag_do_parametro parametro
```
## Parâmetros disponíveis

-h : mostra o help


-o <arquivo> : redireciona a saida para o ‘‘arquivo’’


-f <arquivo> : indica o ‘‘arquivo’’ que contém o grafo de entrada


-s : mostra a solução (em ordem crescente)


-i : vértice inicial (dependendo do algoritmo)


-l : vértice final (dependendo do algoritmo)


* Exempo:
```
make; ./Bellman-Ford -f algo -i 1 -l 2 -s
```



