#include "ListaCircular.h"

// Construtor: inicia a lista como vazia
ListaCircular::ListaCircular() {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}

// Destrutor: libera todos os nós da lista
ListaCircular::~ListaCircular() {
    if (inicio == NULL) return; // lista já está vazia

    NO* atual = inicio;
    do {
        NO* temp = atual;
        atual = atual->prox;
        delete temp;
    } while (atual != inicio);
}

// ===============================================
// Função: InserirInicio
// Insere um novo elemento no início da lista.
// Como a lista é circular, ajustamos os ponteiros
// de "fim" e "inicio" para manter o ciclo fechado.
// ===============================================
void ListaCircular::InserirInicio(int k) {
    NO* novo = new NO;  // cria novo nó
    novo->info = k;

    if (inicio == NULL) { // caso a lista esteja vazia
        novo->prox = novo; // aponta para ele mesmo
        novo->ant = novo;
        inicio = fim = novo;
    } else {
        novo->prox = inicio; // liga novo->prox ao primeiro
        novo->ant = fim;     // liga novo->ant ao último
        inicio->ant = novo;  // ajusta o antigo início
        fim->prox = novo;    // ajusta o último para apontar para o novo
        inicio = novo;       // novo passa a ser o início
    }

    tamanho++;
}

// ===============================================
// Função: Remover
// Remove um elemento específico (valor k) da lista.
// É preciso percorrer a lista circular até achar
// o elemento ou dar a volta completa.
// ===============================================
void ListaCircular::Remover(int k) {
    if (inicio == NULL) {
        cout << "LISTA VAZIA!" << endl;
        return;
    }

    NO* del = inicio;
    // percorre a lista circular procurando o valor
    do {
        if (del->info == k) break;
        del = del->prox;
    } while (del != inicio);

    if (del->info != k) { // percorreu tudo e não achou
        cout << "Elemento inexistente!" << endl;
        return;
    }

    if (del == inicio && del == fim) { // único elemento
        inicio = fim = NULL;
    } else if (del == inicio) { // é o primeiro nó
        inicio = inicio->prox;
        inicio->ant = fim;
        fim->prox = inicio;
    } else if (del == fim) { // é o último nó
        fim = fim->ant;
        fim->prox = inicio;
        inicio->ant = fim;
    } else { // nó no meio
        del->ant->prox = del->prox;
        del->prox->ant = del->ant;
    }

    delete del; // libera a memória
    tamanho--;

    cout << "Elemento " << k << " removido!" << endl;
}