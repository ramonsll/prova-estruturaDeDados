#ifndef LISTA_DP_ENCADEADA_H
#define LISTA_DP_ENCADEADA_H
#include <conio.h> 

// Estrutura de um nó da lista duplamente encadeada
typedef struct No
{
    int info; // Valor armazenado no nó
    No *prox; // Ponteiro para o próximo nó
    No *ant;  // Ponteiro para o nó anterior
} NO;

// Classe que representa a lista duplamente encadeada
class ListaDPEncadeada
{
private:
    NO *inicio;  // Ponteiro para o primeiro nó da lista
    NO *fim;     // Ponteiro para o último nó da lista
    int tamanho; // Número de elementos na lista

public:
    ListaDPEncadeada();
    ~ListaDPEncadeada();

    int ListaVazia();
    void InserirItemInicio(int k);
    void InserirItemFinal(int k);
    void RemoverItem(int k);
    int BuscarItem(int k);
    void ImprimirLista();
    int Menu();
};
#endif // LISTA_DP_ENCADEADA_H
