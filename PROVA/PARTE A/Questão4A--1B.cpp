#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "QuestÃ£o4A--1B.h" // Arquivo de cabeÃƒÂ§alho da lista

using namespace std;

// Construtor da classe ListaEncadeada
ListaEncadeada::ListaEncadeada()
{                  // LETRA A, DA 1 (PARTE B)
    inicio = NULL; // Lista comeÃƒÂ§a vazia
    tamanho = 0;   // Nenhum elemento no inÃƒÂ­cio
    cout << "Inicializando Lista Encadeada!" << endl;
    system("pause"); // Pausa a execuÃƒÂ§ÃƒÂ£o (janela Windows)
}

// Destrutor da classe ListaEncadeada
ListaEncadeada::~ListaEncadeada()
{
    cout << "Destruindo o objeto Lista Encadeada!" << endl;
}

// Verifica se a lista estÃƒÂ¡ vazia
int ListaEncadeada::ListaVazia()
{
    return (inicio == NULL) && (tamanho == 0);
}

// Inserir item no inÃƒÂ­cio da lista
void ListaEncadeada::InserirItem(int k)
{ // LETRA B, DA 1 (PARTE B)
    NO *novo;
    novo = new NO;  // Cria um novo nÃƒÂ³
    novo->info = k; // Atribui o valor ao nÃƒÂ³

    if (ListaVazia())
    { // Caso a lista esteja vazia
        novo->prox = NULL;
        inicio = novo; // Novo nÃƒÂ³ vira o inÃƒÂ­cio
        tamanho++;
    }
    else
    {                        // Caso jÃƒÂ¡ exista elemento
        novo->prox = inicio; // Novo aponta para o antigo primeiro
        inicio->ant = novo;  // Antigo inÃƒÂ­cio aponta de volta para o novo
        inicio = novo;       // Novo nÃƒÂ³ passa a ser o inÃƒÂ­cio
        tamanho++;
    }
}

// Buscar item na lista
int ListaEncadeada::BuscarItem(int k)
{                   // LETRA B, QUESTÃƒÆ’O 3 E LETRA C, DA 1 (PARTE B)
    int achou = -1; // Valor padrÃƒÂ£o: nÃƒÂ£o encontrado
    int pos = 0;    // PosiÃƒÂ§ÃƒÂ£o inicial
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
                pos++; // AvanÃƒÂ§a posiÃƒÂ§ÃƒÂ£o
            }
            copia = copia->prox; // Vai para o prÃƒÂ³ximo
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
    return achou; // Retorna posiÃƒÂ§ÃƒÂ£o ou -1
}

// Remover item da lista
void ListaEncadeada::RemoverItem(int k)
{ // LETRA C, QUESTÃƒÆ’O 3
    NO *del;

    if (ListaVazia())
    { // Lista vazia
        cout << "LISTA VAZIA!" << endl;
    }
    else
    {
        del = inicio;
        // Percorre atÃƒÂ© encontrar ou chegar ao fim
        while ((del->prox != NULL) && (del->info != k))
        {
            del = del->prox;
        }
        if (del == NULL)
        { // NÃƒÂ£o encontrou
            cout << "Elemento inexistente na Lista!" << endl;
        }
        else
        {
            // Ajusta ponteiros ao remover o nÃƒÂ³
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

            delete del; // Libera memoria
            cout << "\nRegistro com o valor " << k << " excluido corretamente! " << endl;
        }
    }
}

// Imprimir todos os elementos da lista
void ListaEncadeada::ImprimirLista()
{ // LETRA A, QUESTÃƒÆ’O 3
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
int ListaEncadeada::GetTamanho()
{ // LETRA D, DA 1 (PARTE B)
    return tamanho;
}

// Menu de opÃƒÂ§ÃƒÂµes da lista
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
    return Opc; // Retorna a opÃƒÂ§ÃƒÂ£o escolhida
}

// FunÃƒÂ§ÃƒÂ£o principal
int main()
{
    ListaEncadeada lista; // Cria objeto lista
    int opcao, valor;

    do
    {
        opcao = lista.Menu(); // Mostra o menu e lÃƒÂª a escolha

        switch (opcao)
        {
        case 1: // Inserir // LETRA B, DA 1 (PARTE B)
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            lista.InserirItem(valor);
            break;

        case 2: // Remover // LETRA C, QUESTÃƒÆ’O 3
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            lista.RemoverItem(valor);
            break;

        case 3: // Imprimir // LETRA A, QUESTÃƒÆ’O 3
            lista.ImprimirLista();
            break;

        case 4: // Buscar // LETRA B, QUESTÃƒÆ’O 3 E LETRA C, DA 1 (PARTE B)
            cout << "Digite o valor a ser buscado: ";
            cin >> valor;
            lista.BuscarItem(valor);
            break;

            case 5:
                cout << "Numero de elementos na lista: "
                     << lista.GetTamanho() << endl;
                break;

        case 6: // Sair
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl;
        }

        system("pause"); // Pausa a execuÃƒÂ§ÃƒÂ£o
    } while (opcao != 6); // Continua atÃƒÂ© escolher sair

    return 0;
}
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Questão4A--1B.h" // Arquivo de cabeÃ§alho da lista

using namespace std;

// Construtor da classe ListaEncadeada
ListaEncadeada::ListaEncadeada()
{                  // LETRA A, DA 1 (PARTE B)
    inicio = NULL; // Lista comeÃ§a vazia
    tamanho = 0;   // Nenhum elemento no inÃ­cio
    cout << "Inicializando Lista Encadeada!" << endl;
    system("pause"); // Pausa a execuÃ§Ã£o (janela Windows)
}

// Destrutor da classe ListaEncadeada
ListaEncadeada::~ListaEncadeada()
{
    cout << "Destruindo o objeto Lista Encadeada!" << endl;
}

// Verifica se a lista estÃ¡ vazia
int ListaEncadeada::ListaVazia()
{
    return (inicio == NULL) && (tamanho == 0);
}

// Inserir item no inÃ­cio da lista
void ListaEncadeada::InserirItem(int k)
{ // LETRA B, DA 1 (PARTE B)
    NO *novo;
    novo = new NO;  // Cria um novo nÃ³
    novo->info = k; // Atribui o valor ao nÃ³

    if (ListaVazia())
    { // Caso a lista esteja vazia
        novo->prox = NULL;
        inicio = novo; // Novo nÃ³ vira o inÃ­cio
        tamanho++;
    }
    else
    {                        // Caso jÃ¡ exista elemento
        novo->prox = inicio; // Novo aponta para o antigo primeiro
        inicio->ant = novo;  // Antigo inÃ­cio aponta de volta para o novo
        inicio = novo;       // Novo nÃ³ passa a ser o inÃ­cio
        tamanho++;
    }
}

// Buscar item na lista
int ListaEncadeada::BuscarItem(int k)
{                   // LETRA B, QUESTÃƒO 3 E LETRA C, DA 1 (PARTE B)
    int achou = -1; // Valor padrÃ£o: nÃ£o encontrado
    int pos = 0;    // PosiÃ§Ã£o inicial
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
                pos++; // AvanÃ§a posiÃ§Ã£o
            }
            copia = copia->prox; // Vai para o prÃ³ximo
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
    return achou; // Retorna posiÃ§Ã£o ou -1
}

// Remover item da lista
void ListaEncadeada::RemoverItem(int k)
{ // LETRA C, QUESTÃƒO 3
    NO *del;

    if (ListaVazia())
    { // Lista vazia
        cout << "LISTA VAZIA!" << endl;
    }
    else
    {
        del = inicio;
        // Percorre atÃ© encontrar ou chegar ao fim
        while ((del->prox != NULL) && (del->info != k))
        {
            del = del->prox;
        }
        if (del == NULL)
        { // NÃ£o encontrou
            cout << "Elemento inexistente na Lista!" << endl;
        }
        else
        {
            // Ajusta ponteiros ao remover o nÃ³
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

            delete del; // Libera memoria
            cout << "\nRegistro com o valor " << k << " excluido corretamente! " << endl;
        }
    }
}

// Imprimir todos os elementos da lista
void ListaEncadeada::ImprimirLista()
{ // LETRA A, QUESTÃƒO 3
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
int ListaEncadeada::GetTamanho()
{ // LETRA D, DA 1 (PARTE B)
    return tamanho;
}

// Menu de opÃ§Ãµes da lista
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
    return Opc; // Retorna a opÃ§Ã£o escolhida
}

// FunÃ§Ã£o principal
int main()
{
    ListaEncadeada lista; // Cria objeto lista
    int opcao, valor;

    do
    {
        opcao = lista.Menu(); // Mostra o menu e lÃª a escolha

        switch (opcao)
        {
        case 1: // Inserir // LETRA B, DA 1 (PARTE B)
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            lista.InserirItem(valor);
            break;

        case 2: // Remover // LETRA C, QUESTÃƒO 3
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            lista.RemoverItem(valor);
            break;

        case 3: // Imprimir // LETRA A, QUESTÃƒO 3
            lista.ImprimirLista();
            break;

        case 4: // Buscar // LETRA B, QUESTÃƒO 3 E LETRA C, DA 1 (PARTE B)
            cout << "Digite o valor a ser buscado: ";
            cin >> valor;
            lista.BuscarItem(valor);
            break;

            case 5:
                cout << "Numero de elementos na lista: "
                     << lista.GetTamanho() << endl;
                break;

        case 6: // Sair
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opcao invalida, tente novamente!" << endl;
        }

        system("pause"); // Pausa a execuÃ§Ã£o
    } while (opcao != 6); // Continua atÃ© escolher sair

    return 0;
}
