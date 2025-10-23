#ifndef LISTA_DP_ENCADEADA_H
#define LISTA_DP_ENCADEADA_H

// Estrutura de um nó da lista duplamente encadeada
struct NO {
    int info;   // Valor armazenado no nó
    NO* prox;   // Ponteiro para o próximo nó
    NO* ant;    // Ponteiro para o nó anterior
};

// Classe que representa a lista duplamente encadeada
class ListaDPEncadeada {
private:
    NO* inicio;   // Ponteiro para o primeiro nó da lista
    NO* fim;      // Ponteiro para o último nó da lista
    int tamanho;  // Número de elementos na lista

public:
    ListaDPEncadeada();   // Construtor
    ~ListaDPEncadeada();  // Destrutor

    int ListaVazia();
    void InserirItemInicio(int k);
    void InserirItemFinal(int k);
    void RemoverItem(int k);
    int BuscarItem(int k);
    void ImprimirLista();
    int Menu();
};

#endif // LISTA_DP_ENCADEADA_H
