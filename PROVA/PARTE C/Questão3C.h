#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <iostream>
using namespace std;

// Estrutura de um nó da lista circular duplamente encadeada
typedef struct NO {
    int info;   // valor armazenado no nó
    NO* prox;   // ponteiro para o próximo nó da lista
    NO* ant;    // ponteiro para o nó anterior da lista
} NO;

// Classe que representa a lista circular duplamente encadeada
class ListaCircular {
private:
    NO* inicio;   // ponteiro para o primeiro nó da lista
    NO* fim;      // ponteiro para o último nó da lista
    int tamanho;  // quantidade de elementos na lista

public:
    ListaCircular();   // construtor: inicializa a lista
    ~ListaCircular();  // destrutor: libera memória e recursos

    void InserirInicio(int k); // insere um elemento no início da lista
    void Remover(int k);       // remove um elemento específico da lista
};

#endif
