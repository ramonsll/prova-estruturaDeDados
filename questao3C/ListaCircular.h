#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <iostream>
using namespace std;

// Estrutura de um nó da lista circular duplamente encadeada
typedef struct NO {
    int info;   // valor armazenado
    NO* prox;   // ponteiro para o próximo nó
    NO* ant;    // ponteiro para o nó anterior
} NO;

// Classe que representa a lista circular duplamente encadeada
class ListaCircular {
private:
    NO* inicio;   // ponteiro para o primeiro nó
    NO* fim;      // ponteiro para o último nó
    int tamanho;  // quantidade de elementos na lista

public:
    ListaCircular();   // construtor
    ~ListaCircular();  // destrutor

    void InserirInicio(int k); // insere um elemento no início
    void Remover(int k);       // remove um elemento específico
};

#endif