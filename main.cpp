#include <iostream>
#include <fmt/core.h>
#include <vector>
#include <random>

using namespace std;

vector<int> generarRutaAleatoria(int tamano){
	random_device rd;
	mt19937 motorRandom(rd()); //Motor Aleatorio
	uniform_int_distribution<int> distr(0, tamano-1); // Distribución uniforme entre 0 y 52

	//lenamos almacen
    int indexa, indexb, val;
	vector<int> almacen(tamano);

    for(int i=0; i < tamano; i++){
        almacen[i] = i+1;
    }

	for(int i=0; i < tamano; i++){
        indexa = distr(motorRandom);
        indexb = distr(motorRandom);
        
        if (indexa == 0 || indexb == 0) continue;

        val = almacen[indexa];
        almacen[indexa] = almacen[indexb];
        almacen[indexb]  = val;
	}

	for (int i=0; i< tamano; i++){
		 std::cout << almacen[i] << " ";
	}
	// for (int num : almacen) {
    //     std::cout << num << " ";
    // }

	return almacen;

	

    // std::vector<int> numeros(tamano);
    // for (int i = 0; i < tamano; ++i) {
    //     numeros[i] = distr(motorRandom);
    // }

	// return numeros;
}

int main()
{
   int tamanoArreglo = 1000000;
    std::vector<int> numerosAleatorios = generarRutaAleatoria(tamanoArreglo);

    // Imprimimos los números generados
    // std::cout << "Números aleatorios generados: ";
    // for (int num : numerosAleatorios) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    return 0;
}

