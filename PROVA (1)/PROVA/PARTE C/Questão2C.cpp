#include <iostream>
#include <stdlib.h>

using namespace std;

// Estrutura do nó da lista duplamente encadeada
struct NO
{
    int info; // valor armazenado no nó
    NO *prox; // ponteiro para o próximo nó
    NO *ant;  // ponteiro para o nó anterior
};

// Classe da lista duplamente encadeada
class ListaDupla
{
private:
    NO *inicio;  // ponteiro para o primeiro nó
    NO *fim;     // ponteiro para o último nó
    int tamanho; // quantidade de elementos na lista

    // Função auxiliar recursiva para busca
    NO *BuscarRecAux(NO *no, int valor)
    {
        if (no == NULL)
            return NULL; // caso base: chegou ao final sem encontrar
        if (no->info == valor)
            return no;                        // encontrou o valor
        return BuscarRecAux(no->prox, valor); // continua a busca no próximo nó
    }

public:
    // Construtor: inicia a lista vazia
    ListaDupla()
    {
        inicio = fim = NULL;
        tamanho = 0;
    }

    // Verifica se a lista está vazia
    bool ListaVaziaLD()
    {
        return inicio == NULL;
    }

    // Insere um elemento no início da lista
    void InserirInicioLD(int k)
    {
        // verifica se o elemento já existe
        NO *temp = inicio;
        while (temp != NULL)
        {
            if (temp->info == k)
            {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        NO *novo = new NO; // cria novo nó
        novo->info = k;
        novo->ant = NULL; // será o primeiro nó

        if (ListaVaziaLD())
        { // se a lista estiver vazia
            novo->prox = NULL;
            inicio = fim = novo; // início e fim apontam para o mesmo nó
        }
        else
        {                        // lista não vazia
            novo->prox = inicio; // novo aponta para antigo início
            inicio->ant = novo;  // antigo início aponta para novo
            inicio = novo;       // atualiza início
        }

        tamanho++; // incrementa tamanho
        cout << "Elemento " << k << " inserido no inicio." << endl;
    }

    // Insere um elemento em uma posição específica
    void InserirPosicao(int k, int pos)
    {
        if (pos < 0 || pos > tamanho)
        { // posição inválida
            cout << "Posicao invalida!" << endl;
            return;
        }

        if (pos == 0)
        { // insere no início
            InserirInicioLD(k);
            return;
        }

        // verifica duplicata
        NO *temp = inicio;
        while (temp != NULL)
        {
            if (temp->info == k)
            {
                cout << "Elemento " << k << " ja existe na lista!" << endl;
                return;
            }
            temp = temp->prox;
        }

        NO *novo = new NO; // cria novo nó
        novo->info = k;

        temp = inicio;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->prox;

        novo->prox = temp->prox; // ajusta próximo do novo
        novo->ant = temp;        // ajusta anterior do novo
        if (temp->prox != NULL)
            temp->prox->ant = novo; // ajusta anterior do próximo nó
        else
            fim = novo;    // atualiza fim se for inserido no final
        temp->prox = novo; // ajusta próximo do nó anterior

        tamanho++; // incrementa tamanho
        cout << "Elemento " << k << " inserido na posicao " << pos << "." << endl;
    }

    // Imprime todos os elementos da lista
    void Imprimir()
    {
        NO *temp = inicio;
        cout << "Lista: ";
        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->prox;
        }
        cout << endl;
    }

    // Busca recursiva de um elemento
    NO *BuscarRec(int valor)
    {
        return BuscarRecAux(inicio, valor);
    }

    // Exclui um elemento por posição
    void Excluir(int pos)
    {
        if (ListaVaziaLD())
        { // lista vazia
            cout << "Lista vazia!" << endl;
            return;
        }

        if (pos < 0 || pos >= tamanho)
        { // posição inválida
            cout << "Posicao invalida!" << endl;
            return;
        }

        NO *temp = inicio;

        if (pos == 0)
        { // remove o primeiro nó
            inicio = temp->prox;
            if (inicio != NULL)
                inicio->ant = NULL;
            else
                fim = NULL; // lista ficou vazia
            delete temp;
            tamanho--;
            cout << "Elemento da posicao 0 excluido." << endl;
            return;
        }

        // percorre até a posição
        for (int i = 0; i < pos; i++)
            temp = temp->prox;

        // ajusta ponteiros do nó anterior e próximo
        if (temp->ant != NULL)
            temp->ant->prox = temp->prox;
        if (temp->prox != NULL)
            temp->prox->ant = temp->ant;
        else
            fim = temp->ant; // atualiza fim se for o último

        delete temp; // libera memória
        tamanho--;
        cout << "Elemento da posicao " << pos << " excluido." << endl;
    }

    // Retorna tamanho da lista
    int Tamanho() { return tamanho; }
};

// Função principal com menu
int main()
{
    ListaDupla lista;
    int opcao, valor, pos;

    do
    {
        cout << "========================================================" << endl;
        cout << "            ESCOLHA UMA OPCAO NO MENU LISTA " << endl;
        cout << "========================================================" << endl;
        cout << "  [1] INSERIR NO INICIO DA FILA                         " << endl;
        cout << "  [2] INSERIR EM POSICAO ALEATORIA                      " << endl;
        cout << "  [3] IMPRIMIR LISTA                                    " << endl;
        cout << "  [4] BUSCAR ELEMENTO                                   " << endl;
        cout << "  [5] EXCLUIR ELEMENTO POR POSICAO                       " << endl;
        cout << "  [6] MOSTRAR TAMANHO DA LISTA                          " << endl;
        cout << "  [0] SAIR DO PROGRAMA                                  " << endl;
        cout << "--------------------------------------------------------" << endl;

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a inserir no inicio: ";
            cin >> valor;
            lista.InserirInicioLD(valor);
            break;
        case 2:
            cout << "Digite o valor a inserir: ";
            cin >> valor;
            cout << "Digite a posicao: ";
            cin >> pos;
            lista.InserirPosicao(valor, pos);
            break;
        case 3:
            lista.Imprimir();
            break;
        case 4:
            cout << "Digite o valor a buscar: ";
            cin >> valor;
            if (lista.BuscarRec(valor) != NULL)
                cout << "Elemento " << valor << " encontrado!" << endl;
            else
                cout << "Elemento " << valor << " nao encontrado!" << endl;
            break;
        case 5:
            cout << "Digite a posicao a excluir: ";
            cin >> pos;
            lista.Excluir(pos);
            break;
        case 6:
            cout << "Tamanho atual da lista: " << lista.Tamanho() << endl;
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
