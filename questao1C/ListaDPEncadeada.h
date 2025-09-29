#ifndef LISTA_DP_ENCADEADA_H
#define LISTA_DP_ENCADEADA_H
#include <conio.h> 

typedef struct No{
    int info;
    No *prox;
    No *ant;
}NO;

class ListaDPEncadeada{
    private:
        NO *inicio;
        NO *fim;
        int tamanho;

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