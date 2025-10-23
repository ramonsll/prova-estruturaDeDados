#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <iostream>
using namespace std;

// Estrutura de um nó da lista circular duplamente encadeada
struct NO_C {
    int info;   // valor armazenado no nó
    NO_C* prox; // ponteiro para o próximo nó da lista
    NO_C* ant;  // ponteiro para o nó anterior da lista
};

// Classe que representa a lista circular duplamente encadeada
class ListaCircular {
private:
    NO_C* inicio;   // ponteiro para o primeiro nó da lista
    NO_C* fim;      // ponteiro para o último nó da lista
    int tamanho;    // quantidade de elementos na lista

public:
    ListaCircular();   // construtor: inicializa a lista
    ~ListaCircular();  // destrutor: libera memória e recursos

    void InserirInicio(int k); // insere um elemento no início da lista
    void InserirFinal(int k);  // insere um elemento no final da lista
    void Remover(int k);       // remove um elemento específico da lista
    void ImprimirLista();      // exibe todos os elementos da lista
    int Menu();                // exibe menu de opções
};

#endif
