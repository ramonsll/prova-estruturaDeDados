#include "ListaCircular.h"

// Construtor: inicia a lista como vazia
ListaCircular::ListaCircular() {
    inicio = NULL;  // sem elementos no início
    fim = NULL;     // sem elementos no fim
    tamanho = 0;    // tamanho inicial zero
}

// Destrutor: libera todos os nós da lista
ListaCircular::~ListaCircular() {
    if (inicio == NULL) return; // lista já está vazia, nada a liberar

    NO* atual = inicio;  // começa pelo início
    do {
        NO* temp = atual;       // guarda nó atual
        atual = atual->prox;    // avança para o próximo nó
        delete temp;            // libera memória do nó
    } while (atual != inicio);  // repete até voltar ao início
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
// Função: Remover
// Remove um elemento específico (valor k) da lista.
// É preciso percorrer a lista circular até achar
// o elemento ou dar a volta completa.
// ===============================================
void ListaCircular::Remover(int k) {
    if (inicio == NULL) { // lista vazia
        cout << "LISTA VAZIA!" << endl;
        return;
    }

    NO* del = inicio;
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
