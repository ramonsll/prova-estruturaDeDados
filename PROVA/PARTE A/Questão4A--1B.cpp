#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "ListaEncadeada.h" // Arquivo de cabeçalho da lista

using namespace std;

// Construtor da classe ListaEncadeada
ListaEncadeada::ListaEncadeada()
{                  // LETRA A, DA 1 (PARTE B)
    inicio = NULL; // Lista começa vazia
    tamanho = 0;   // Nenhum elemento no início
    cout << "Inicializando Lista Encadeada!" << endl;
    system("pause"); // Pausa a execução (janela Windows)
}

// Destrutor da classe ListaEncadeada
ListaEncadeada::~ListaEncadeada()
{
    cout << "Destruindo o objeto Lista Encadeada!" << endl;
}

// Verifica se a lista está vazia
int ListaEncadeada::ListaVazia()
{
    return (inicio == NULL) && (tamanho == 0);
}

// Inserir item no início da lista
void ListaEncadeada::InserirItem(int k)
{ // LETRA B, DA 1 (PARTE B)
    NO *novo;
    novo = new NO;  // Cria um novo nó
    novo->info = k; // Atribui o valor ao nó

    if (ListaVazia())
    { // Caso a lista esteja vazia
        novo->prox = NULL;
        inicio = novo; // Novo nó vira o início
        tamanho++;
    }
    else
    {                        // Caso já exista elemento
        novo->prox = inicio; // Novo aponta para o antigo primeiro
        inicio->ant = novo;  // Antigo início aponta de volta para o novo
        inicio = novo;       // Novo nó passa a ser o início
        tamanho++;
    }
}

// Buscar item na lista
int ListaEncadeada::BuscarItem(int k)
{                   // LETRA B, QUESTÃO 3 E LETRA C, DA 1 (PARTE B)
    int achou = -1; // Valor padrão: não encontrado
    int pos = 0;    // Posição inicial
    NO *copia;

    if (ListaVazia())
    { // Lista sem elementos
        cout << "LISTA VAZIA!" << endl;
    }
    else
    {
        copia = inicio;
        while (copia != NULL)
        { // Percorre a lista
            if (copia->info == k)
            { // Encontrou
                achou = pos;
                break;
            }
            else
            {
                pos++; // Avança posição
            }
            copia = copia->prox; // Vai para o próximo
        }
    }
    // Mensagens de retorno
    if (achou != -1)
    {
        cout << "Elemento " << k << " encontrado na posicao " << achou << endl;
    }
    else
    {
        cout << "Elemento inexistente na Lista!" << endl;
    }
    return achou; // Retorna posição ou -1
}

// Remover item da lista
void ListaEncadeada::RemoverItem(int k)
{ // LETRA C, QUESTÃO 3
    NO *del;

    if (ListaVazia())
    { // Lista vazia
        cout << "LISTA VAZIA!" << endl;
    }
    else
    {
        del = inicio;
        // Percorre até encontrar ou chegar ao fim
        while ((del->prox != NULL) && (del->info != k))
        {
            del = del->prox;
        }
        if (del == NULL)
        { // Não encontrou
            cout << "Elemento inexistente na Lista!" << endl;
        }
        else
        {
            // Ajusta ponteiros ao remover o nó
            if (inicio == del)
            {
                inicio = del->prox;
            }
            if (del->prox != NULL)
            {
                del->prox->ant = del->ant;
            }
            if (del->ant != NULL)
            {
                del->ant->prox = del->prox;
            }
            tamanho--; // Diminui tamanho da lista

            delete del; // Libera memória
            cout << "\nRegistro com o valor " << k << " excluido corretamente! " << endl;
        }
    }
}

// Imprimir todos os elementos da lista
void ListaEncadeada::ImprimirLista()
{ // LETRA A, QUESTÃO 3
    NO *copia;
    copia = inicio;
    int cont = 1;

    if (ListaVazia() || inicio == NULL)
    {
        cout << "LISTA VAZIA!" << endl;
    }
    else
    {
        while (copia != NULL)
        { // Percorre toda a lista
            cout << "LISTA[" << cont << "] = " << copia->info << endl;
            copia = copia->prox;
            cont++;
        }
    }
}

// Retorna o tamanho da lista
int GetTamanho(int tamanho)
{ // LETRA D, DA 1 (PARTE B)
    return tamanho;
}

// Menu de opções da lista
int ListaEncadeada::Menu(void)
{
    int Opc;
    system("cls"); // Limpa tela
    cout << "========================================================" << endl;
    cout << "            ESCOLHA UMA OPCAO NO MENU LISTA " << endl;
    cout << "========================================================" << endl;
    cout << "  [1] INSERIR DADO NA LISTA                             " << endl;
    cout << "  [2] EXCLUIR DADO DA LISTA                             " << endl;
    cout << "  [3] IMPRIMIR A LISTA                                  " << endl;
    cout << "  [4] BUSCAR DADO NA LISTA                              " << endl;
    cout << "  [5] VER TAMANHO DA LISTA                              " << endl;
    cout << "  [6] SAIR DO PROGRAMA                                  " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  OPCAO ESCOLHIDA: ";
    cin >> Opc;
    return Opc; // Retorna a opção escolhida
}

// Função principal
int main()
{
    ListaEncadeada lista; // Cria objeto lista
    int opcao, valor;

    do
    {
        opcao = lista.Menu(); // Mostra o menu e lê a escolha

        switch (opcao)
        {
        case 1: // Inserir // LETRA B, DA 1 (PARTE B)
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            lista.InserirItem(valor);
            break;

        case 2: // Remover // LETRA C, QUESTÃO 3
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            lista.RemoverItem(valor);
            break;

        case 3: // Imprimir // LETRA A, QUESTÃO 3
            lista.ImprimirLista();
            break;

        case 4: // Buscar // LETRA B, QUESTÃO 3 E LETRA C, DA 1 (PARTE B)
            cout << "Digite o valor a ser buscado: ";
            cin >> valor;
            lista.BuscarItem(valor);
            break;

        case 5: // Ver tamanho // LETRA D, DA 1 (PARTE B)
            // ⚠ Aqui há um problema: está chamando GetTamanho errado
            cout << "Numero de elementos na lista: "
                 << lista.GetTamanho(int tamanho) << endl;
            break;

        case 6: // Sair
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl;
        }

        system("pause"); // Pausa a execução
    } while (opcao != 6); // Continua até escolher sair

    return 0;
}
