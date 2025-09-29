#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <conio.h> 

typedef struct No{
    int info;
    No *prox;
    No *ant;
}NO;

class ListaEncadeada{
    private:
        NO *inicio;
        int tamanho;
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        int ListaVazia(); 
        void InserirItem(int k);
        void RemoverItem(int k);
        int BuscarItem(int k);
        void ImprimirLista();
        int GetTamanho(int tamanho);
        int Menu();
};
#endif // LISTA_ENCADEADA_H