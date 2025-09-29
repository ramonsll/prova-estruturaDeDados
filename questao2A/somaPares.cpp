#include <iostream>
using namespace std;

// função recursiva p imprimir e somar os pares
int somaPares(int n){
    if (n<0) return 0;
    if (n==0){
        cout << 0; 
        return 0;
    }
    if(n % 2 != 0) return somaPares(n-1);

    int soma = somaPares (n-2); 
    cout << " + " << n;
    return soma + n;
}

int main(){
    int n;
    cout<<"Digite um numero: ";
    cin>>n;

    int resultado = somaPares(n);
    cout << "=" << resultado << endl;

    return 0;
}
