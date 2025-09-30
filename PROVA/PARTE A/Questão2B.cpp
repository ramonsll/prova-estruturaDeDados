#include <iostream>
using namespace std;

// Definição de um nó da lista encadeada
typedef struct Reg
{
    int infor; // Valor armazenado no nó
    Reg *prox; // Ponteiro para o próximo nó
} No;

// Estrutura da pilha
typedef struct TipoPilha
{
    No *Topo;    // Ponteiro para o nó do topo da pilha
    int tamanho; // Quantidade de elementos na pilha
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *p)
{
    p->Topo = NULL; // Pilha começa vazia
    p->tamanho = 0; // Nenhum elemento inicialmente
}

// Inserir elementos (push)
void push(Pilha *p, int valor)
{
    No *novo = new No;    // Cria um novo nó
    novo->infor = valor;  // Armazena o valor dentro do nó
    novo->prox = p->Topo; // O próximo do novo nó será o antigo topo
    p->Topo = novo;       // Atualiza o topo para o novo nó
    p->tamanho++;         // Incrementa o tamanho da pilha
    cout << "Elemento " << valor << " inserido na pilha.\n";
}

// Remover elementos (pop)
int pop(Pilha *p)
{
    if (p->Topo == NULL) // Verifica se a pilha está vazia
    {
        cout << "Pilha vazia, nada a remover.\n";
        return -1; // Retorna valor inválido
    }
    No *remover = p->Topo;      // Nó que será removido
    int valor = remover->infor; // Guarda o valor do nó removido
    p->Topo = remover->prox;    // Atualiza o topo para o próximo nó
    delete remover;             // Libera memória do nó removido
    p->tamanho--;               // Decrementa o tamanho da pilha
    cout << "Elemento " << valor << " removido da pilha.\n";
    return valor; // Retorna o valor removido
}

// Listar conteúdo da pilha
void listar(Pilha *p)
{
    if (p->Topo == NULL) // Verifica se a pilha está vazia
    {
        cout << "A pilha esta vazia.\n";
        return;
    }

    cout << "Conteudo da pilha (do topo para base): ";
    No *aux = p->Topo; // Ponteiro auxiliar para percorrer a pilha
    while (aux != NULL)
    {
        cout << aux->infor << " "; // Exibe o valor do nó
        aux = aux->prox;           // Avança para o próximo nó
    }
    cout << endl;
}

// Buscar elemento na pilha
bool buscar(Pilha *p, int valor)
{
    No *aux = p->Topo; // Ponteiro auxiliar para percorrer
    while (aux != NULL)
    {
        if (aux->infor == valor) // Se o valor for encontrado
        {
            cout << "Elemento " << valor
                 << " encontrado na pilha.\n";
            return true; // Retorna verdadeiro
        }
        aux = aux->prox; // Avança para o próximo nó
    }
    // Se não encontrar, informa o usuário
    cout << "Elemento " << valor << " NAO encontrado na pilha.\n";
    return false;
}

// Função principal com menu
int main()
{
    Pilha p;              // Declara uma pilha
    inicializarPilha(&p); // Inicializa a pilha

    int opcao, valor; // Variáveis para menu e valores

    do
    {
        // Exibição do menu
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
        cin >> opcao; // Lê a escolha do usuário

        // Executa a ação de acordo com a opção escolhida
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            push(&p, valor); // Insere na pilha
            break;
        case 2:
            pop(&p); // Remove do topo
            break;
        case 3:
            listar(&p); // Lista elementos
            break;
        case 4:
            cout << "Digite o valor a buscar: ";
            cin >> valor;
            buscar(&p, valor); // Busca valor
            break;
        case 0:
            cout << "Saindo...\n"; // Encerra programa
            break;
        default:
            cout << "Opcao invalida!\n"; // Opção inexistente
        }

    } while (opcao != 0); // Repete até escolher sair

    return 0;
}
