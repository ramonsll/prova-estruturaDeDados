//Fizemos uma complementaÃƒÂ§ao de questÃƒÂµes, uma vez que a questÃƒÂ£o 4 da parte A e a questÃƒÂ£o 1 da parte B se tratavam
//de listas encadeadas.


#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <conio.h>  // Biblioteca usada para funcoes de console (Windows)

// Estrutura que define um no da lista
typedef struct No{
    int info;   // Valor armazenado no no
    No *prox;   // Ponteiro para o proximo no da lista
    No *ant;    // Ponteiro para o no anterior (lista duplamente encadeada)
}NO;

// Classe que representa a lista encadeada
class ListaEncadeada{
    private:
        NO *inicio;   // Ponteiro para o primeiro no da lista
        int tamanho;  // Quantidade de elementos armazenados

    public:
        // Construtor: inicializa os atributos
        ListaEncadeada();

        // Destrutor: libera recursos (caso precise)
        ~ListaEncadeada();

        // Verifica se a lista esta vazia
        int ListaVazia(); 

        // Insere um elemento no inicio da lista
        void InserirItem(int k);

        // Remove um elemento da lista (busca pelo valor)
        void RemoverItem(int k);

        // Busca um elemento na lista e retorna a posicao
        int BuscarItem(int k);

        // Imprime todos os elementos da lista
        void ImprimirLista();

        // Retorna o tamanho da lista
        int GetTamanho();

        // Exibe o menu e retorna a opcao escolhida
        int Menu();
};
#endif // LISTA_ENCADEADA_H

//Fizemos uma complementaÃ§ao de questÃµes, uma vez que a questÃ£o 4 da parte A e a questÃ£o 1 da parte B se tratavam
//de listas encadeadas.


#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <conio.h>  // Biblioteca usada para funcoes de console (Windows)

// Estrutura que define um nÃ³ da lista
typedef struct No{
    int info;   // Valor armazenado no nó
    No *prox;   // Ponteiro para o proximo no da lista
    No *ant;    // Ponteiro para o no anterior (lista duplamente encadeada)
}NO;

// Classe que representa a lista encadeada
class ListaEncadeada{
    private:
        NO *inicio;   // Ponteiro para o primeiro no da lista
        int tamanho;  // Quantidade de elementos armazenados

    public:
        // Construtor: inicializa os atributos
        ListaEncadeada();

        // Destrutor: libera recursos (caso precise)
        ~ListaEncadeada();

        // Verifica se a lista esta vazia
        int ListaVazia(); 

        // Insere um elemento no inicio da lista
        void InserirItem(int k);

        // Remove um elemento da lista (busca pelo valor)
        void RemoverItem(int k);

        // Busca um elemento na lista e retorna a posiÃ§Ã£o
        int BuscarItem(int k);

        // Imprime todos os elementos da lista
        void ImprimirLista();

        // Retorna o tamanho da lista
        int GetTamanho();

        // Exibe o menu e retorna a opcao escolhida
        int Menu();
};
#endif // LISTA_ENCADEADA_H