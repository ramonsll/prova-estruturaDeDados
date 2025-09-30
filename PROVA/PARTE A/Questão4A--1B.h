//Fizemos uma complementaçao de questões, uma vez que a questão 4 da parte A e a questão 1 da parte B se tratavam
//de listas encadeadas.


#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <conio.h>  // Biblioteca usada para funções de console (Windows)

// Estrutura que define um nó da lista
typedef struct No{
    int info;   // Valor armazenado no nó
    No *prox;   // Ponteiro para o próximo nó da lista
    No *ant;    // Ponteiro para o nó anterior (lista duplamente encadeada)
}NO;

// Classe que representa a lista encadeada
class ListaEncadeada{
    private:
        NO *inicio;   // Ponteiro para o primeiro nó da lista
        int tamanho;  // Quantidade de elementos armazenados

    public:
        // Construtor: inicializa os atributos
        ListaEncadeada();

        // Destrutor: libera recursos (caso precise)
        ~ListaEncadeada();

        // Verifica se a lista está vazia
        int ListaVazia(); 

        // Insere um elemento no início da lista
        void InserirItem(int k);

        // Remove um elemento da lista (busca pelo valor)
        void RemoverItem(int k);

        // Busca um elemento na lista e retorna a posição
        int BuscarItem(int k);

        // Imprime todos os elementos da lista
        void ImprimirLista();

        // Retorna o tamanho da lista
        int GetTamanho(int tamanho);

        // Exibe o menu e retorna a opção escolhida
        int Menu();
};
#endif // LISTA_ENCADEADA_H
