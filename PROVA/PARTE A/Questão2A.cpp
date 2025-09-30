#include <iostream>
using namespace std;

// Função recursiva para imprimir e somar os números pares até n
int somaPares(int n){
    if (n < 0) return 0;  // Caso base: números negativos não entram na soma

    if (n == 0){          // Caso base: chegou no 0
        cout << 0;        // Imprime o zero
        return 0;         // Soma inicial é zero
    }

    if(n % 2 != 0)        // Se o número for ímpar, ignora e chama recursão com (n-1)
        return somaPares(n-1);

    // Se o número for par:
    int soma = somaPares(n-2); // Chama recursivamente para o próximo par menor
    cout << " + " << n;        // Imprime o número atual na sequência da soma
    return soma + n;           // Retorna a soma acumulada
}

int main(){
    int n;
    cout << "Digite um numero: "; 
    cin >> n;  // Lê o valor do usuário

    int resultado = somaPares(n);  // Chama a função recursiva
    cout << "=" << resultado << endl; // Mostra o resultado final da soma

    return 0;
}
