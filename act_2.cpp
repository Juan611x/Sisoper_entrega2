#include <iostream>

int main(){
    int numero = 42; // Declaración y asignación de una variable entera
    int* punteroNumero = &numero; // Declaración de un puntero que apunta a ’numero'

    std::cout << "Valor de 'numero' a través del puntero: " << *punteroNumero << std::endl;
    *punteroNumero = 100;
    std::cout << "Nuevo valor de 'numero': " << numero << std::endl;
    int& referenciaNumero = numero; // Declaración de una referencia
    referenciaNumero = 200;

    std::cout << "Nuevo valor de 'numero' a través de la referencia: " << numero << std::endl;

    return 0;

}

