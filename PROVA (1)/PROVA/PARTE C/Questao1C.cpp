#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Questao1C.h"

using namespace std;

// Construtor da lista duplamente encadeada
ListaDPEncadeada::ListaDPEncadeada(){ 
    inicio = fim = NULL;   // Lista começa vazia
    tamanho = 0;           // Tamanho inicial zero
    cout <<"Inicializando Lista Duplamente Encadeada!"<<endl;
    system("pause");
}

// Destrutor da lista (libera memória)
ListaDPEncadeada::~ListaDPEncadeada(){
    NO* atual = inicio;
    while(atual != NULL){
        NO* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    cout <<"Destruindo o objeto Lista Duplamente Encadeada!"<<endl;
}

// Verifica se a lista está vazia
int ListaDPEncadeada::ListaVazia(){
    return (tamanho == 0);
}

// Inserir elemento no início da lista
void ListaDPEncadeada::InserirItemInicio(int k){
    NO* novo = new NO;      // Cria novo nó
    novo->info = k;         
    novo->ant = NULL;       

    if(ListaVazia()){       
        novo->prox = NULL;
        inicio = fim = novo; 
    } else {                
        novo->prox = inicio; 
        inicio->ant = novo;  
        inicio = novo;       
    }
    tamanho++;
}

// Inserir elemento no final da lista
void ListaDPEncadeada::InserirItemFinal(int k){
    NO* novo = new NO;
    novo->info = k;
    novo->prox = NULL;      

    if(ListaVazia()){       
        novo->ant = NULL;
        inicio = fim = novo;
    } else {                
        novo->ant = fim;    
        fim->prox = novo;   
        fim = novo;         
    }
    tamanho++;
}

// Imprimir todos os elementos da lista
void ListaDPEncadeada::ImprimirLista(){
    NO* copia = inicio;     
    int cont = 1;

    if(ListaVazia()){
        cout <<"LISTA VAZIA!"<<endl;
    } else {
        while(copia != NULL){ 
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
        while((del != NULL) && (del->info != k)){ 
            del = del->prox;
        }
        if(del == NULL){
            cout<<"Elemento inexistente na Lista!"<<endl;  
        } else {
            if(inicio == del) inicio = del->prox;           
            if(fim == del) fim = del->ant;                  
            if(del->prox != NULL) del->prox->ant = del->ant; 
            if(del->ant != NULL) del->ant->prox = del->prox; 
            tamanho--; 
            delete del;                                    
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
        while((aux != NULL) && (aux->info != k)){ 
            aux = aux->prox;
            pos++;
        }
        if(aux == NULL){ 
            cout<<"Elemento inexistente na Lista!"<<endl;  
            return -1;
        } else {        
            cout<<"\nRegistro com o valor "<< k <<" encontrado na posicao "<< pos <<endl;
            return pos;
        }
    }
}

// Exibir menu de opções para o usuário
int ListaDPEncadeada::Menu(){
    int Opc;
    system("cls"); 
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
        opc = lista.Menu(); 

        switch(opc){
            case 1: 
                cout<<"Digite o valor a ser inserido no inicio da lista: ";
                cin>>valor;
                lista.InserirItemInicio(valor);
                system("pause");
                break;
            case 2: 
                cout<<"Digite o valor a ser inserido no fim da lista: ";
                cin>>valor;
                lista.InserirItemFinal(valor);
                system("pause");
                break;
            case 3: 
                cout<<"Digite o valor a ser excluido da lista: ";
                cin>>valor;
                lista.RemoverItem(valor);
                system("pause");
                break;
            case 4: 
                lista.ImprimirLista();
                system("pause");
                break;
            case 5: 
                cout<<"Digite o valor a ser buscado na lista: ";
                cin>>valor;
                lista.BuscarItem(valor);
                system("pause");
                break;
            case 6: 
                cout<<"Saindo do programa..."<<endl;
                break;
            default: 
                cout<<"Opcao invalida! Tente novamente."<<endl;
                system("pause");
        }
    }while(opc != 6);

    return 0;
}
