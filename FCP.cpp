// Punto #2 (Funciones con parametros)

#include <iostream>

double CuadradoDeUnNumero(double x){
    return x * x;
}

double CuboDeUnNumero(double x){
    return x * x * x;
}



double DobleDeUnNumero(double x){
    return 2 * x;
}

double TripleDeUnNumero(double x){
    return 3 * x;
}

double InversoDeUnNumero(double x){
    if(x !=0){
        return 1/x;
    }
    return 0;
}

void AplicarFuncion(double* Arreglo, int n, double (*funcion)(double)){
    for(int i = 0; i < n; i++){
        Arreglo[i] = funcion(Arreglo[i]);
    }
}

int run(){
    int tamano;
    std::cout << "Por favor, ingrese el tamano de el arreglo:  ";
    std::cin >> tamano;

    double* arreglo = new double[tamano];

    for(int i = 0; i < tamano; i++){
        std::cout << "Posicion del arreglo: " << "[" << i << "]";
        std::cin >> arreglo[i];
    }

    int opcion;
    std::cout << "Por favor ingrese que funcion desea aplicar: \n";
    std::cout << "1. El cuadrado de un numero (x^2)" << '\n' << "2. El cubo de un numero (x^3) \n" << "3. El doble de un numero (2x) \n" << "4. El triple de un numero (3x) \n" << "5. El inverso de un numero(x^-1) \n" << "Inciso: ";
    std::cin >> opcion;

    switch(opcion){
        case 1:{
            std::cout << "\n Has escogido aplicar el cuadrado de un numero a todos los elementos. \n";
            AplicarFuncion(arreglo, tamano, CuadradoDeUnNumero);
            break;
        }
        case 2:{
            std::cout << "\n Has escogido aplicar el cubo de un numero a todos los elementos. \n";
            AplicarFuncion(arreglo, tamano, CuboDeUnNumero);
            break;
        }
        case 3:{
           std::cout << " \n Has escogido aplicar el doble de un numero a todos los elementos. \n";
            AplicarFuncion(arreglo, tamano, DobleDeUnNumero);
            break;
        }
        case 4:{
            std::cout << "Has escogido aplicar el triple de un numero a todos los elementos. \n";
            AplicarFuncion(arreglo, tamano, TripleDeUnNumero);
            break;
        }
        case 5:{
            std::cout << "Has escogido aplicar la inversa de un numero a todos los elementos. \n";
            AplicarFuncion(arreglo, tamano, InversoDeUnNumero);
            break;
        }
        default:{
            std::cout << "Opcion marcada no valida";
            break;
        }
    }

    for(int i = 0; i < tamano; i++){
        std::cout << arreglo[i] << " ";
    }
    
    delete[] arreglo;
    return 0;
}

int main(){
    run();
    return 0;
}
