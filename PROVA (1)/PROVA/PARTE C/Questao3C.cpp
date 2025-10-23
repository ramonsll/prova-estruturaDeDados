#include "Questao3C.h"
#include <cstdlib>
#include <iostream>
using namespace std;

// Construtor: inicia a lista como vazia
ListaCircular::ListaCircular() {
    inicio = NULL;  // sem elementos no início
    fim = NULL;     // sem elementos no fim
    tamanho = 0;    // tamanho inicial zero
}

// Destrutor: libera todos os nós da lista
ListaCircular::~ListaCircular() {
    if (inicio == NULL) return; // lista já está vazia, nada a liberar

    NO_C* atual = inicio;  // começa pelo início
    do {
        NO_C* temp = atual;       // guarda nó atual
        atual = atual->prox;      // avança para o próximo nó
        delete temp;              // libera memória do nó
    } while (atual != inicio);    // repete até voltar ao início
}

// ===============================================
// Função: InserirInicio
// Insere um novo elemento no início da lista.
// ===============================================
void ListaCircular::InserirInicio(int k) {
    NO_C* novo = new NO_C;  // cria novo nó
    novo->info = k;

    if (inicio == NULL) { // caso a lista esteja vazia
        novo->prox = novo; // aponta para ele mesmo
        novo->ant = novo;
        inicio = fim = novo; // início e fim apontam para o mesmo nó
    } else {               // lista não está vazia
        novo->prox = inicio; // novo aponta para antigo início
        novo->ant = fim;     // novo aponta para o fim
        inicio->ant = novo;  // antigo início aponta para o novo
        fim->prox = novo;    // fim aponta para o novo início
        inicio = novo;       // atualiza início
    }

    tamanho++; // incrementa tamanho da lista
}

// ===============================================
// Função: InserirFinal
// Insere um novo elemento no final da lista.
// ===============================================
void ListaCircular::InserirFinal(int k) {
    NO_C* novo = new NO_C;
    novo->info = k;

    if (inicio == NULL) { // lista vazia
        novo->prox = novo;
        novo->ant = novo;
        inicio = fim = novo;
    } else { // lista não vazia
        novo->prox = inicio;   // próximo do novo é o início
        novo->ant = fim;       // anterior do novo é o fim atual
        fim->prox = novo;      // fim atual aponta para o novo
        inicio->ant = novo;    // início aponta para o novo
        fim = novo;            // atualiza fim
    }

    tamanho++; // incrementa tamanho
}

// ===============================================
// Função: Remover
// Remove um elemento específico (valor k) da lista.
// ===============================================
void ListaCircular::Remover(int k) {
    if (inicio == NULL) { // lista vazia
        cout << "LISTA VAZIA!" << endl;
        return;
    }

    NO_C* del = inicio;
    // percorre a lista circular procurando o valor
    do {
        if (del->info == k) break;
        del = del->prox;
    } while (del != inicio);

    if (del->info != k) { // percorreu tudo e não encontrou
        cout << "Elemento inexistente!" << endl;
        return;
    }

    if (del == inicio && del == fim) { // único elemento da lista
        inicio = fim = NULL;
    } else if (del == inicio) { // nó a ser removido é o primeiro
        inicio = inicio->prox;   // atualiza início
        inicio->ant = fim;       // ajusta ponteiro do início
        fim->prox = inicio;      // fim aponta para o novo início
    } else if (del == fim) { // nó a ser removido é o último
        fim = fim->ant;         // atualiza fim
        fim->prox = inicio;     // fim aponta para início
        inicio->ant = fim;      // início aponta para novo fim
    } else { // nó está no meio
        del->ant->prox = del->prox; // antecessor aponta para próximo
        del->prox->ant = del->ant;  // próximo aponta para antecessor
    }

    delete del; // libera memória do nó
    tamanho--;  // decrementa tamanho da lista

    cout << "Elemento " << k << " removido!" << endl;
}

// ===============================================
// Função: ImprimirLista
// Percorre a lista circular e mostra os elementos
// ===============================================
void ListaCircular::ImprimirLista() {
    if (inicio == NULL) {
        cout << "LISTA VAZIA!" << endl;
        return;
    }

    NO_C* atual = inicio;
    int pos = 1;
    cout << "Elementos da lista: " << endl;
    do {
        cout << "Posicao " << pos << " = " << atual->info << endl;
        atual = atual->prox;
        pos++;
    } while (atual != inicio);
}

// ===============================================
// Função: Menu
// Exibir menu de opções para o usuário
// ===============================================
int ListaCircular::Menu() {
    int Opc;
    system("cls"); // Limpa a tela
    cout<<"========================================================"<<endl;
    cout<< "            ESCOLHA UMA OPCAO NO MENU LISTA "<<endl;
    cout<<"========================================================"<<endl;
    cout<<"  [1] INSERIR DADO NO INICIO DA LISTA                   "<<endl;
    cout<<"  [2] INSERIR DADO NO FINAL DA LISTA                    "<<endl;
    cout<<"  [3] REMOVER DADO DA LISTA                             "<<endl;
    cout<<"  [4] MOSTRAR LISTA                                     "<<endl;
    cout<<"  [5] SAIR DO PROGRAMA                                  "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"  OPCAO ESCOLHIDA: ";
    cin>>Opc;
    return Opc;
}

// ===============================================
// Função principal
// ===============================================
int main() {
    ListaCircular lista; // cria objeto da lista
    int opc, valor;      // declara variáveis

    do {
        opc = lista.Menu(); // Mostra menu e lê opção

        switch(opc) {
            case 1: // Inserir no início
                cout<<"Digite o valor a ser inserido no inicio da lista: ";
                cin>>valor;
                lista.InserirInicio(valor);
                system("pause");
                break;

            case 2: // Inserir no fim
                cout<<"Digite o valor a ser inserido no final da lista: ";
                cin>>valor;
                lista.InserirFinal(valor);
                system("pause");
                break;

            case 3: // Remover
                cout<<"Digite o valor a ser removido da lista: ";
                cin>>valor;
                lista.Remover(valor);
                system("pause");
                break;

            case 4: // Mostrar lista
                lista.ImprimirLista();
                system("pause");
                break;

            case 5: // Sair
                cout<<"Saindo do programa..."<<endl;
                break;

            default: // Opção inválida
                cout<<"Opcao invalida! Tente novamente."<<endl;
                system("pause");
        }
    } while (opc != 5);

    return 0;
}
