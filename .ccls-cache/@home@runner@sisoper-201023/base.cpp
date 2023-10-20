#include <iostream>
#include <vector>

class GestorMemoria {
  private:
    int tamanoMemoria;
    std::vector<int> memoria;
  public:
    GestorMemoria(int tamano): tamanoMemoria(tamano), memoria(tamano, -1) {}
    
};