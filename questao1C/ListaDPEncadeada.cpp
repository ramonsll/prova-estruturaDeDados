#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "ListaEncadeada.h"

using namespace std;

ListaDPEncadeada::ListaDPEncadeada(){ 
    inicio = fim = NULL; 
    tamanho = 0;
    cout <<"Inicializando Lista Duplamente Encadeada!"<<endl;
    system("pause");
}

ListaDPEncadeada::~ListaDPEncadeada(){
    cout <<"Destruindo o objeto Lista Duplamente Encadeada!"<<endl;
}
int ListaDPEncadeada::ListaVazia(){
    return (inicio == fim == NULL) && (tamanho == 0);
}

void ListaDPEncadeada::InserirItemInicio(int k){
    NO* novo;
    novo = new NO;
    novo->info = k; // conteudo eh k
    novo->ant = NULL; // anterior eh NULL pq eh no inicio

    if(ListaVazia()){
        novo->prox = NULL;
        inicio = fim = novo;
        tamanho++;
    }
    else{
        novo->prox = inicio; 
        inicio->ant = novo; 
        inicio = novo; 
        tamanho++;
    }
}

void ListaDPEncadeada::InserirItemFinal(int k){
    NO* novo;
    novo = new NO;
    novo->info = k; // conteudo eh k
    novo->prox = NULL; // proximo eh NULL pq eh no fim
    if(ListaVazia()){
        novo->ant = NULL;
        inicio =  fim = novo;
        tamanho++;
    }
    else{
        novo->ant = fim; 
        fim->prox = novo; 
        fim = novo; 
        tamanho++;
    }
}

// função p imprimir os valores da lista
void ListaDPEncadeada::ImprimirLista(){
    NO* copia;
    copia = inicio;
    int cont = 1;

    if(ListaVazia() || inicio == NULL){
        cout <<"LISTA VAZIA!"<<endl;
    }else{
        while(copia != NULL){ // percorrer a lista ate chegar no final
            cout<<"LISTA["<<cont<<"] = "<< copia->info <<endl;
            copia=copia->prox;
            cont++;
        }
    }
}

// função p remover item especifico

void ListaDPEncadeada::RemoverItem(int k){
    NO* del;
    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
    }else{
        del = inicio;
        while((del != NULL) && (del->info != k)){
            del = del->prox;
        }
        if(del == NULL){
            cout<<"Elemento inexistente na Lista!"<<endl;  
        }else{
            // se o no a ser excluido for o do inicio
            if(inicio == del){
                inicio = del->prox;
            }

            // apaga o proximo do anterior caso n seja o do inicio
            if(del->prox != NULL){
                del->prox->ant = del->ant;
            }

            // apaga o anterior do proximo caso n seja o do fim
            if(del->ant != NULL){
                del->ant->prox = del->prox;
            }
            tamanho--;
            
            // libera memoria
            delete del;
            cout<<"\nRegistro com o valor "<< k <<" excluido corretamente! "<<endl;
        }
    }
}
// função p buscar item especifico 
int ListaDPEncadeada::BuscarItem(int k){
    NO* aux;
    int pos = 1;
    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
        return -1;
    }else{
        aux = inicio;
        while((aux != NULL) && (aux->info != k)){
            aux = aux->prox;
            pos++;
        }
        if(aux == NULL){ // chegou ao final e n encontrou 
            cout<<"Elemento inexistente na Lista!"<<endl;  
            return -1;
        }else{
            cout<<"\nRegistro com o valor "<< k <<" encontrado na posicao "<< pos <<endl;
            return pos;
        }
    }
}

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