#include <iostream>



int main() {
    const int tamañoArray = 5;
    int numeros[tamañoArray] = {10, 20, 30, 40, 50}; // Dcclaraei6n de un array de enteros

    // Imprimir el contenido del array
    std::cout << "Contenido del array 'numeros': ";
    for (int i = 0; i < tamañoArray; i++){
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    int* punteroNumeros = numeros;

    punteroNumeros[1] = 99;

    std::cout << "Contenido del array 'numeros' despues de la modificacion: ";
    for (int i = 0; i < tamañoArray; i++){
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}