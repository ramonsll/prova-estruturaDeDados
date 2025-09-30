#include <iostream>
using namespace std;

// Definição de um nó da lista encadeada (cada elemento da pilha)
typedef struct Reg
{
    int infor; // Valor armazenado no nó
    Reg *prox; // Ponteiro para o próximo nó da pilha
} No;

// Estrutura que representa a pilha
typedef struct TipoPilha
{
    No *Topo;    // Ponteiro para o nó do topo da pilha
    int tamanho; // Quantidade de elementos na pilha
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *p)
{
    p->Topo = NULL; // Pilha começa vazia
    p->tamanho = 0; // Sem elementos
}

// Inserir elemento na pilha (push)
void push(Pilha *p, int valor)
{
    No *novo = new No;    // Cria um novo nó
    novo->infor = valor;  // Armazena o valor
    novo->prox = p->Topo; // Aponta para o antigo topo
    p->Topo = novo;       // Novo nó passa a ser o topo
    p->tamanho++;         // Incrementa o tamanho da pilha
    cout << "Elemento " << valor << " inserido na pilha.\n";
}

// Remover elemento da pilha (pop)
int pop(Pilha *p)
{
    if (p->Topo == NULL)
    { // Verifica se a pilha está vazia
        cout << "Pilha vazia, nada a remover.\n";
        return -1; // Retorna valor inválido
    }
    No *remover = p->Topo;      // Nó que será removido
    int valor = remover->infor; // Armazena o valor do nó
    p->Topo = remover->prox;    // Atualiza o topo para o próximo nó
    delete remover;             // Libera a memória do nó removido
    p->tamanho--;               // Decrementa o tamanho
    cout << "Elemento " << valor << " removido da pilha.\n";
    return valor; // Retorna o valor removido
}

// Listar conteúdo da pilha
void listar(Pilha *p)
{
    if (p->Topo == NULL)
    { // Se a pilha estiver vazia
        cout << "A pilha esta vazia.\n";
        return;
    }

    cout << "Conteudo da pilha (do topo para base): ";
    No *aux = p->Topo; // Ponteiro auxiliar para percorrer
    while (aux != NULL)
    {
        cout << aux->infor << " "; // Imprime valor do nó
        aux = aux->prox;           // Avança para o próximo nó
    }
    cout << endl;
}

// Buscar um elemento na pilha
bool buscar(Pilha *p, int valor)
{
    No *aux = p->Topo; // Ponteiro auxiliar para percorrer
    while (aux != NULL)
    {
        if (aux->infor == valor)
        { // Elemento encontrado
            cout << "Elemento " << valor
                 << " encontrado na pilha.\n";
            return true;
        }
        aux = aux->prox; // Avança para o próximo nó
    }
    cout << "Elemento " << valor << " NAO encontrado na pilha.\n";
    return false; // Retorna falso se não encontrado
}

// Função principal com menu interativo
int main()
{
    Pilha p;              // Cria uma pilha
    inicializarPilha(&p); // Inicializa a pilha

    int opcao, valor; // Variáveis para menu e valores

    do
    {
        // Exibe menu de opções

        cout << "========================================================" << endl;
        cout << "            ESCOLHA UMA OPCAO NO MENU LISTA " << endl;
        cout << "========================================================" << endl;
        cout << "  [1] INSERIR ELEMENTOS                                 " << endl;
        cout << "  [2] REMOVER ELEMENTOS                                 " << endl;
        cout << "  [3] LISTAR PILHA                                      " << endl;
        cout << "  [4] BUSCAR ELEMENTO                                   " << endl;
        cout << "  [0] SAIR DO PROGRAMA                                  " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao; // Lê opção do usuário

        // Executa ação de acordo com a opção escolhida
        switch (opcao)
        {
        case 1: // Inserir elemento
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            push(&p, valor);
            break;
        case 2: // Remover elemento
            pop(&p);
            break;
        case 3: // Listar pilha
            listar(&p);
            break;
        case 4: // Buscar elemento
            cout << "Digite o valor a buscar: ";
            cin >> valor;
            buscar(&p, valor);
            break;
        case 0: // Sair
            cout << "Saindo...\n";
            break;
        default: // Opção inválida
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 0); // Repete até escolher sair

    return 0; // Fim do programa
}
