#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class proceso{
  public:
    int id;
    int tamano;

    proceso(int id, int tamano): id(id), tamano(tamano){}
};

class GestorMemoria{
  private:
    int tamanoMemoria;
    std::vector<std::vector<int>> memoria;
    std::vector<int> tamanos;
  public:
    GestorMemoria(int tamanoM) : tamanoMemoria(tamanoM), 
                                memoria(tamanoM, std::vector<int>()), 
                                tamanos(tamanoM, 0){}

    bool assignarMemoriaFirstFit(proceso p){
      for(int i = 0; i < tamanoMemoria; i++){
        if(tamanos[i] >= p.tamano){
          memoria[i].push_back(p.id);
          tamanos[i] -= p.tamano;
          return true;
        }
      }
      return false;
    }

    bool assignarMemoriaBesttFit(proceso p){

      std::vector<int> opciones = {};
      
      
      for(int i = 0; i < tamanoMemoria; i++){
        if(tamanos[i] >= p.tamano){
          opciones.push_back(i);
        }
      }

      int m = opciones[0];
      for(int o : opciones){
        if(tamanos[m] > tamanos[o]){
          m = o;
        }  
      }
      
      if(tamanos[m] >= p.tamano){
        memoria[m].push_back(p.id);
        tamanos[m] -= p.tamano;
        return true;
      }
      return false;
    }

    bool assignarMemoriaWorstFit(proceso p){
      int m = 0;
      for(int i = 0; i < tamanoMemoria; i++){
        if(tamanos[i] >= p.tamano){
          if(tamanos[m] - p.tamano < tamanos[i] - p.tamano){
            m = i;
          }
        }
      }
      if(tamanos[m] >= p.tamano){
        memoria[m].push_back(p.id);
        tamanos[m] -= p.tamano;
        return true;
      }
      return false;
    }

    void asignarTamano(int direccion, int tamano){
      tamanos[direccion] = tamano; 
    }

    void librerarMemoria(proceso p){
      for(int i = 0; i < tamanoMemoria; i++){
        for(auto j = memoria[i].begin(); j != memoria[i].end(); j++){
          if(*j == p.id){
            memoria[i].erase(j);
            tamanos[i] += p.tamano;
            return;
          }
        }
      }
    }

    void imprimirEstadoMemoria(){
      std::cout << "Estado de la memoria: " << std::endl;
      for(int i = 0; i < tamanoMemoria; i++){
        std::cout << "Bloque " << i <<": (" << tamanos[i] << ")  ";
        for(int j = 0; j < memoria[i].size(); j++){
          std::cout << memoria[i][j] << " ";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
};

int main(){
  std::string nombreArchivoEntrada = "archivo_entrada.txt";

  std::ifstream archivoEntrada(nombreArchivoEntrada);
  if(!archivoEntrada.is_open()){
    std::cout << "Error al crear el archivo de entrada" << std::endl;
    return 1;
  }

  std::vector<std::string> lineas = {};
  std::string linea;
  while(std::getline(archivoEntrada, linea)){
    if(linea.empty() || linea[0] == '#'){
      continue;
    }
    lineas.push_back(linea);

  }
  


  GestorMemoria gestor(std::stoi(lineas[1]));

  std::istringstream stream(lineas[2]);
  std::string parte;
  int i = 0;
  while (std::getline(stream, parte, ',')) {
      int numero = std::stoi(parte);
      gestor.asignarTamano(i, numero);
      i++;
  }

  int protocolo = std::stoi(lineas[3]);

  
  
  for(int i = 4; i < lineas.size(); i++){

    std::vector<int> valores = {0, 0};

    std::istringstream stream2(lineas[i]);
    std::string parte2;
    int j = 0;
    while (std::getline(stream2, parte2, ',')) {
        int numero = std::stoi(parte2);
        valores[j] = numero;
        j++;
    }

    proceso p = proceso(valores[0], valores[1]);
    std::cout << "Asignando proceso " << p.id << std::endl;
    switch(protocolo){
      case 1:
        gestor.assignarMemoriaFirstFit(p);
        break;
      case 2:
        gestor.assignarMemoriaBesttFit(p);
        break;
      case 3:
        gestor.assignarMemoriaWorstFit(p);
        break;
      default:
        std::cout << "Opción no válida." << std::endl;
        break;
    }
      gestor.imprimirEstadoMemoria();
  }

  archivoEntrada.close();
  return 0;
}
