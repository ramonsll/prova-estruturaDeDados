#include <iostream>  // biblioteca para entrada e saída de dados (cout, cin)
#include <cstdlib>   // biblioteca para funções do sistema (ex: system("pause"))

using namespace std;

// Definição da classe Rec
class Rec
{
public:
    Rec();  // construtor
    ~Rec(); // destrutor

    // Assinatura das funções recursivas
    int f1(int n); // fatorial
    int f2(int n); // relação de recorrência
    int f3(int n); // impressão regressiva
    int Menu();    // exibe o menu
};

// Construtor
Rec::Rec()
{ // é chamado quando o programa inicia
    cout << "Parte A: Questao 1" << endl;
    system("pause"); // pausa a execução até o usuário pressionar uma tecla
}

// Destrutor
Rec::~Rec()
{ // chamado automaticamente quando o objeto deixa de existir
    cout << "Fim da questao!" << endl;
}

// Função recursiva que calcula o fatorial
int Rec::f1(int n)
{
    if (n == 0)
        return 1; // caso base: fatorial de 0 é 1
    else
        return (n * f1(n - 1)); // chamada recursiva
}

// Função recursiva com relação de recorrência:

int Rec::f2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else
        return (f2(n - 1) + 2 * f2(n - 2)); // chamada recursiva dupla
}

// Função recursiva que imprime os números em ordem regressiva até 0
int Rec::f3(int n)
{
    if (n == 0)
        cout << "Zero" << endl; // caso base: chegou em zero
    else
    {
        cout << n << endl; // imprime o valor atual
        f3(n - 1);         // chamada recursiva para imprimir o anterior
    }
    return 0;
}

// -------- MENU DAS FUNÇÕES --------
int Rec::Menu()
{
    int opc;

    cout << "========================================================" << endl;
    cout << "            ESCOLHA UMA OPCAO NO MENU LISTA " << endl;
    cout << "========================================================" << endl;
    cout << "  [1] FUNCAO 1 - FATORIAL                               " << endl;
    cout << "  [2] FUNCAO 2 - RECORRENCIA                            " << endl;
    cout << "  [3] FUNCAO 3 - IMPRESSAO REGRESSIVA                   " << endl;
    cout << "  [0] SAIR DO PROGRAMA                                  " << endl;
    cout << "--------------------------------------------------------" << endl;
    
    cout << "Escolha uma opcao: \n";
    cin >> opc; 
    return opc; 
}

// ------ PROGRAMA PRINCIPAL -------
int main()
{
    Rec r; // criação do objeto (chama automaticamente o construtor)
    int n, opc;

    do
    {
        int opc = r.Menu(); // mostra o menu e lê a opção
        if (opc == 0)       // caso o usuário digite 0, encerra o programa
        {
            cout << "Saindo do programa..." << endl;
            break;
        }

        cout << "Digite um valor: \n"; // pede um valor ao usuário
        cin >> n;

        // Executa a função escolhida
        switch (opc)
        {
        case 1:
            cout << "Resultado do valor " << n << " inserido na funcao 1 = " << r.f1(n) << endl;
            break;

        case 2:
            cout << "Resultado do valor " << n << " inserido na funcao 2  = " << r.f2(n) << endl;
            break;

        case 3:
            cout << "Resultado do valor " << n << " inserido na funcao 3 = " << endl;
            r.f3(n);
            break;

        default:
            cout << "Opcao invalida!" << endl; // caso o usuário escolha algo fora do menu
        }
    } while (opc != 0); // repete o menu até a opção 0 ser escolhida

    return 0;
}
