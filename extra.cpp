#include <iostream>

void obtenerDireccionStack() {
    int stackVariable;
    std::cout << "Dirección del stackVariable: " << &stackVariable << std::endl;
}

int main() {
    obtenerDireccionStack();
    int* heapMemory = new int;
    std::cout << "Dirección de la memoria asignada en el heap: " << heapMemory << std::endl;
    std::cout << "Dirección de la funcion main: " << (void*)main << std::endl;

    delete heapMemory;

    return 0;
}