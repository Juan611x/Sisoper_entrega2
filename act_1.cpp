#include <iostream>



int main() {
    int numero = 42; // Declaración y asignación de una variable entera

    // Imprimir el valor de la variable
    std::cout << "Valor de la variable 'numero': " << numero << std::endl;

    //Imprimir la dirección de memorla de la variable
    std::cout << "Dirección de memoria de 'numero': " << &numero << std::endl;

    // Utilizar un puntero para modificar el valor de la variable
    int* punteroNumero = &numero;  // Declaracion de un puntero que apunta a ' numero '
    *punteroNumero = 100;  

    // Imprimir el nuevo valor de la variable
    std::cout << "Nuevo valor de la variable 'numero': " << numero << std::endl;
    return 0;
}