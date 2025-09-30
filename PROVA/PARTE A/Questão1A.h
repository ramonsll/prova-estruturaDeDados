#include <conio.h>

class Rec{ //criação de uma classe 
    public: 
    Rec(); //método construtor 

    private:
    ~Rec(); //método destrutor

    //modificadores
    int f1(int n);
    int f2(int n);
    int f3(int n);

    //acessores
    int Menu();
    int opc;
};