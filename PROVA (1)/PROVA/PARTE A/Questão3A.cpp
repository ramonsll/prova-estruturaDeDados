#include <iostream>  // biblioteca padrão para entrada e saída de dados (cin, cout)
#include <cstdlib>   // biblioteca com funções do sistema (ex: system("pause"))

using namespace std;

// Definição da classe Rec
class Rec
{
public: // criação de uma classe pública
    Rec();  // construtor
    ~Rec(); // destrutor

    // Variáveis públicas (não usadas dentro da classe neste exemplo)
    int a; 
    int b;
    int opc;
};

// Construtor da classe Rec
Rec::Rec()
{ // é chamado quando o programa inicia
    cout << "Parte A: Questao 3\n"
         << endl;
    system("pause"); // pausa a execução até o usuário pressionar uma tecla
}

// Destrutor da classe Rec
Rec::~Rec()
{ // chamado automaticamente quando o objeto deixa de existir
    cout << "Fim da questao!" << endl;
}

// Função recursiva que calcula o produto de "a * b" usando apenas somas sucessivas
int produto(int a, int b) // função recursiva
{
    if (b == 1) // caso base: quando b chega a 1, o resultado é apenas "a"
    {
        return a;
    }
    else // passo recursivo: soma "a" ao resultado de produto(a, b-1)
    {
        return produto(a, b - 1) + a;
    }
}
 
// ------ PROGRAMA PRINCIPAL -------
int main()
{
    int a, b, opc; // variáveis para armazenar os valores
    Rec r;         // criação de um objeto da classe Rec (chama automaticamente o construtor)

    do
    {
        // Entrada de dados
        cout << "Digite um valor para 'a': ";
        cin >> a;

        cout << "Digite um valor para 'b': ";
        cin >> b;

        // Validação: b precisa ser maior ou igual a 1
        if (b < 1)
        {
            cout << "Erro! O valor de b deve ser maior ou igual a 1!\n"
                 << endl;
        }
        else
        {
            // Chamada da função recursiva para calcular o produto
            cout << a << " * " << b << " = " << produto(a, b) << endl;
        }

        // Pergunta ao usuário se deseja repetir
        cout << "Deseja continuar?\n";
        cout << "1 - sim\n2 - nao\n";
        cin >> opc;

    } while (opc == 1); // repete enquanto o usuário digitar 1 (sim)

    return 0; // fim do programa
}
