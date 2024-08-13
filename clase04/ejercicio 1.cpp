#include <iostream>

std::string ImprimirLado(int longitud) {

    std::string charChain = std::string(longitud - 1, 'x') + "x\n";

    return charChain;
}

std::string ImprimirLaterales(int longitud) {

    std::string charChain = "x" + std::string(longitud - 2, ' ') + "x\n";

    return charChain;
}

void ImprimirPatron(int lado) {
    
    for (int i = 1; i <= lado; ++i) {
        
        if (i == 1 || i == lado) {
            std::cout << ImprimirLado(lado);            
        }
        else {
            std::cout << ImprimirLaterales(lado);
        }
    }
}

int main()
{
    int lado;
    std::cout << "Ingresar el valor del lado del cuadradon";
    std::cin >> lado;
    ImprimirPatron(lado);
    
}