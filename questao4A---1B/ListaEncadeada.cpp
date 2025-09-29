#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "ListaEncadeada.h"

using namespace std;

ListaEncadeada::ListaEncadeada(){ //LETRA A, DA 1 (PARTE B)
    inicio = NULL; 
    tamanho = 0;
    cout <<"Inicializando Lista Encadeada!"<<endl;
    system("pause");
}

ListaEncadeada::~ListaEncadeada(){
    cout <<"Destruindo o objeto Lista Encadeada!"<<endl;
}

int ListaEncadeada::ListaVazia(){
    return (inicio == NULL) && (tamanho == 0);
}
void ListaEncadeada::InserirItem(int k){ // LETRA B, DA 1 (PARTE B)
    NO *novo;
    novo = new NO;
    novo->info = k;

    if(ListaVazia()){
        novo->prox = NULL;
        inicio = novo;
        tamanho++;
    }else{
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
        tamanho++;
    }
}
int ListaEncadeada::BuscarItem(int k){ // LETRA B, QUESTÃO 3 E LETRA C, DA 1 (PARTE B)
    int achou = -1;
    int pos = 0;
    NO *copia;

    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
    }
    else{
        copia = inicio;
        while(copia != NULL){
            if(copia->info == k){
                achou = pos;
                break;
            }else{
                pos++;
            }
            copia = copia->prox;
        }
    }
    if(achou != -1){
        cout<<"Elemento "<< k <<" encontrado na posicao "<< achou <<endl;
    }else{
        cout<<"Elemento inexistente na Lista!"<<endl;
    }
    return achou;
}
void ListaEncadeada::RemoverItem(int k){ // LETRA C, QUESTÃO 3
    NO* del;

    if(ListaVazia()){
        cout<<"LISTA VAZIA!"<<endl;
    }
    else{
        del = inicio;
        while((del->prox != NULL) && (del->info != k)){
            del = del->prox;
        }
        if(del == NULL){
            cout<<"Elemento inexistente na Lista!"<<endl;
        }
        else{
            if(inicio == del){
                inicio = del->prox;
            }
            if(del->prox != NULL){
                del->prox->ant = del->ant;
            }
            if(del->ant != NULL){
                del->ant->prox = del->prox;
            }
            tamanho--;

            delete del;
            cout<<"\nRegistro com o valor "<< k <<" excluido corretamente! "<<endl;
        }
    }
}
void ListaEncadeada::ImprimirLista(){ //LETRA A, QUESTÃO 3
    NO *copia;
    copia = inicio;
    int cont = 1;

    if(ListaVazia() || inicio == NULL){
        cout<<"LISTA VAZIA!"<<endl;
    }
    else{
        while (copia != NULL){
            cout<<"LISTA["<<cont<<"] = "<< copia->info <<endl;
            copia = copia->prox;
            cont++;
        }
    }
}
int GetTamanho(int tamanho) { // LETRA D, DA 1 (PARTE B)
    return tamanho; 
}

int ListaEncadeada::Menu(void)
{ int Opc;
  system("cls");
  cout<<"========================================================"<<endl;
  cout<< "            ESCOLHA UMA OPCAO NO MENU LISTA "<<endl;
  cout<<"========================================================"<<endl;
  cout<<"  [1] INSERIR DADO NA LISTA                             "<<endl;
  cout<<"  [2] EXCLUIR DADO DA LISTA                             "<<endl;
  cout<<"  [3] IMPRIMIR A LISTA                                  "<<endl;
  cout<<"  [4] BUSCAR DADO NA LISTA                              "<<endl;
  cout<<"  [5] VER TAMANHO DA LISTA                              "<<endl;
  cout<<"  [6] SAIR DO PROGRAMA                                  "<<endl;
  cout<<"--------------------------------------------------------"<<endl;
  cout<<"  OPCAO ESCOLHIDA: ";
  cin>>Opc;
  return Opc;
}

int main() {
    ListaEncadeada lista;
    int opcao, valor;

    do {
        opcao = lista.Menu();

        switch (opcao) {
            case 1: // Inserir // LETRA B, DA 1 (PARTE B)
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                lista.InserirItem(valor);
                break;

            case 2: // REMOVER - LETRA C, QUESTÃO 3
                cout << "Digite o valor a ser removido: "; 
                cin >> valor;
                lista.RemoverItem(valor);
                break;

            case 3: // IMPRIMIR - LETRA A, QUESTÃO 3
                lista.ImprimirLista();
                break;

            case 4: // BUSCAR - LETRA B, QUESTÃO 3 E LETRA C, DA 1 (PARTE B)
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                lista.BuscarItem(valor);
                break;
            
            case 5: // VER TAMANHO  // LETRA D, DA 1 (PARTE B)
                cout << "Numero de elementos na lista: " << lista.GetTamanho(int tamanho) << endl;
            break;

            case 6: // Sair
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opcao invalida, tente novamente!" << endl;
        }

        system("pause"); 
    } while (opcao != 6);

    return 0;
}

