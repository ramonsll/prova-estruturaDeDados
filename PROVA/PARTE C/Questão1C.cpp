#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "ListaEncadeada.h"

using namespace std;

// Construtor da lista duplamente encadeada
ListaDPEncadeada::ListaDPEncadeada(){ 
    inicio = fim = NULL;   // Lista começa vazia
    tamanho = 0;           // Tamanho inicial zero
    cout <<"Inicializando Lista Duplamente Encadeada!"<<endl;
    system("pause");
}

// Destrutor da lista
ListaDPEncadeada::~ListaDPEncadeada(){
    cout <<"Destruindo o objeto Lista Duplamente Encadeada!"<<endl;
}

// Verifica se a lista está vazia
int ListaDPEncadeada::ListaVazia(){
    return (inicio == fim == NULL) && (tamanho == 0);
}

// Inserir elemento no início da lista
void ListaDPEncadeada::InserirItemInicio(int k){
    NO* novo = new NO;      // Cria novo nó
    novo->info = k;         // Atribui valor
    novo->ant = NULL;       // Não há nó anterior (é o início)

    if(ListaVazia()){        // Se a lista está vazia
        novo->prox = NULL;
        inicio = fim = novo; // Inicio e fim apontam para o novo nó
        tamanho++;
    } else {                 // Se a lista já tem elementos
        novo->prox = inicio; // Novo nó aponta para antigo início
        inicio->ant = novo;  // Antigo início aponta para novo nó
        inicio = novo;       // Atualiza início
        tamanho++;
    }
}

// Inserir elemento no final da lista
void ListaDPEncadeada::InserirItemFinal(int k){
    NO* novo = new NO;
    novo->info = k;
    novo->prox = NULL;      // Não há nó seguinte (é o fim)

    if(ListaVazia()){       // Lista vazia
        novo->ant = NULL;
        inicio = fim = novo;
        tamanho++;
    } else {                // Lista não vazia
        novo->ant = fim;    // Novo nó aponta para antigo fim
        fim->prox = novo;   // Antigo fim aponta para novo nó
        fim = novo;         // Atualiza fim
        tamanho++;
    }
}

// Imprimir todos os elementos da lista
void ListaDPEncadeada::ImprimirLista(){
    NO* copia = inicio;     // Ponteiro auxiliar
    int cont = 1;

    if(ListaVazia() || inicio == NULL){
        cout <<"LISTA VAZIA!"<<endl;
    } else {
        while(copia != NULL){ // Percorre toda a lista
            cout<<"LISTA["<<cont<<"] = "<< copia->info <<endl;
            copia = copia->prox;
            cont++;
        }
    }
}

// Remover item específico da lista
void ListaDPEncadeada::RemoverItem(int k){
    NO* del;
    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
    } else {
        del = inicio;
        while((del != NULL) && (del->info != k)){ // Busca pelo valor
            del = del->prox;
        }
        if(del == NULL){
            cout<<"Elemento inexistente na Lista!"<<endl;  
        } else {
            if(inicio == del) inicio = del->prox;          // Atualiza início se for o primeiro nó
            if(del->prox != NULL) del->prox->ant = del->ant; // Atualiza ponteiro do próximo nó
            if(del->ant != NULL) del->ant->prox = del->prox; // Atualiza ponteiro do nó anterior
            tamanho--; 
            delete del;                                    // Libera memória
            cout<<"\nRegistro com o valor "<< k <<" excluido corretamente! "<<endl;
        }
    }
}

// Buscar item específico na lista
int ListaDPEncadeada::BuscarItem(int k){
    NO* aux;
    int pos = 1;
    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
        return -1;
    } else {
        aux = inicio;
        while((aux != NULL) && (aux->info != k)){ // Percorre até encontrar ou chegar ao fim
            aux = aux->prox;
            pos++;
        }
        if(aux == NULL){ // Não encontrado
            cout<<"Elemento inexistente na Lista!"<<endl;  
            return -1;
        } else {        // Encontrado
            cout<<"\nRegistro com o valor "<< k <<" encontrado na posicao "<< pos <<endl;
            return pos;
        }
    }
}

// Exibir menu de opções para o usuário
int ListaDPEncadeada::Menu(){
    int Opc;
    system("cls"); // Limpa a tela
    cout<<"========================================================"<<endl;
    cout<< "            ESCOLHA UMA OPCAO NO MENU LISTA "<<endl;
    cout<<"========================================================"<<endl;
    cout<<"  [1] INSERIR DADO NO INICIO DA LISTA                   "<<endl;
    cout<<"  [2] INSERIR DADO NO FIM DA LISTA                      "<<endl;
    cout<<"  [3] EXCLUIR DADO DA LISTA                             "<<endl;
    cout<<"  [4] IMPRIMIR A LISTA                                  "<<endl;
    cout<<"  [5] CONSULTAR DADO NA LISTA                           "<<endl;
    cout<<"  [6] SAIR DO PROGRAMA                                  "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"  OPCAO ESCOLHIDA: ";
    cin>>Opc;
    return Opc;
}

// Função principal com menu interativo
int main(){
    ListaDPEncadeada lista;
    int opc, valor;

    do{
        opc = lista.Menu(); // Mostra menu e lê opção

        switch(opc){
            case 1: // Inserir no início
                cout<<"Digite o valor a ser inserido no inicio da lista: ";
                cin>>valor;
                lista.InserirItemInicio(valor);
                system("pause");
                break;
            case 2: // Inserir no fim
                cout<<"Digite o valor a ser inserido no fim da lista: ";
                cin>>valor;
                lista.InserirItemFinal(valor);
                system("pause");
                break;
            case 3: // Remover item
                cout<<"Digite o valor a ser excluido da lista: ";
                cin>>valor;
                lista.RemoverItem(valor);
                system("pause");
                break;
            case 4: // Imprimir lista
                lista.ImprimirLista();
                system("pause");
                break;
            case 5: // Buscar item
                cout<<"Digite o valor a ser buscado na lista: ";
                cin>>valor;
                lista.BuscarItem(valor);
                system("pause");
                break;
            case 6: // Sair
                cout<<"Saindo do programa..."<<endl;
                break;
            default: // Opção inválida
                cout<<"Opcao invalida! Tente novamente."<<endl;
                system("pause");
        }
    }while(opc != 6);

    return 0;
}
