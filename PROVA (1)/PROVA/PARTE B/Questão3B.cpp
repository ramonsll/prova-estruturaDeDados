#include <iostream>
using namespace std;

// Definição de um nó da fila (cada elemento da fila)
typedef struct Reg {
    int infor;   // Valor armazenado no nó
    Reg *prox;   // Ponteiro para o próximo nó da fila
} No;

// Estrutura que representa a fila
typedef struct TipoFila {
    No *frente;  // Ponteiro para o primeiro elemento (frente)
    No *tras;    // Ponteiro para o último elemento (trás)
    int tamanho; // Quantidade de elementos na fila
} Fila;

// Inicializa a fila (vazia)
void inicializarFila(Fila *f) {
    f->frente = NULL;  // Sem elementos na frente
    f->tras = NULL;    // Sem elementos no final
    f->tamanho = 0;    // Tamanho zero
}

// Inserir elemento na fila (enqueue)
void enqueue(Fila *f, int valor) {
    No *novo = new No;   // Cria um novo nó
    novo->infor = valor; // Armazena o valor
    novo->prox = NULL;   // Último nó aponta para NULL

    if (f->tras == NULL) {   // Fila vazia
        f->frente = novo;    // Novo nó é a frente
    } else {
        f->tras->prox = novo; // Anexa ao final da fila
    }
    f->tras = novo;       // Atualiza o ponteiro do final
    f->tamanho++;         // Incrementa o tamanho

    cout << "Elemento " << valor << " inserido na fila.\n";
}

// Remover elemento da fila (dequeue)
int dequeue(Fila *f) {
    if (f->frente == NULL) {   // Verifica se a fila está vazia
        cout << "Fila vazia, nada a remover.\n";
        return -1;
    }
    No *remover = f->frente;   // Nó a ser removido
    int valor = remover->infor; // Armazena valor
    f->frente = remover->prox;  // Atualiza a frente
    if (f->frente == NULL) {    // Se a fila ficou vazia
        f->tras = NULL;         // Atualiza o ponteiro do final
    }
    delete remover;             // Libera memória
    f->tamanho--;               // Decrementa tamanho
    cout << "Elemento " << valor << " removido da fila.\n";
    return valor;               // Retorna valor removido
}

// Listar conteúdo da fila
void listar(Fila *f) {
    if (f->frente == NULL) {            // Fila vazia
        cout << "A fila esta vazia.\n";
        return;
    }

    cout << "Conteudo da fila (da frente para o final): ";
    No *aux = f->frente;                // Ponteiro auxiliar
    while (aux != NULL) {                
        cout << aux->infor << " ";      // Imprime valor do nó
        aux = aux->prox;                // Avança para o próximo
    }
    cout << endl;
}

// Buscar elemento na fila
bool buscar(Fila *f, int valor) {
    No *aux = f->frente;                // Ponteiro auxiliar
    while (aux != NULL) {
        if (aux->infor == valor) {      // Elemento encontrado
            cout << "Elemento " << valor << " encontrado na fila.\n";
            return true;
        }
        aux = aux->prox;                // Avança para o próximo
    }
    cout << "Elemento " << valor << " NAO encontrado na fila.\n";
    return false;                        // Não encontrado
}

// Função principal com menu interativo
int main() {
    Fila f;                   // Cria a fila
    inicializarFila(&f);      // Inicializa vazia

    int opcao, valor;         // Variáveis para menu e valores

    do {
        // Exibe menu de opções
        cout << "\n===== MENU FILA =====\n";
        cout << "1 - Inserir elemento (enqueue)\n";
        cout << "2 - Remover elemento (dequeue)\n";
        cout << "3 - Listar fila\n";
        cout << "4 - Buscar elemento\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Executa ação de acordo com a opção
        switch (opcao) {
            case 1:                 // Inserir elemento
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                enqueue(&f, valor);
                break;
            case 2:                 // Remover elemento
                dequeue(&f);
                break;
            case 3:                 // Listar fila
                listar(&f);
                break;
            case 4:                 // Buscar elemento
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                buscar(&f, valor);
                break;
            case 0:                 // Sair
                cout << "Saindo...\n";
                break;
            default:                // Opção inválida
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);       // Repete até o usuário escolher sair

    return 0;                    // Fim do programa
}
