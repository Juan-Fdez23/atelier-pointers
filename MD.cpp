// Punto #1 (Matriz Dinamica + operaciones por punteros)
#include <iostream>

void plusfilas(int ** array2d, int n, int m){
    for(int i = 0; i < n; i++){
        int suma = 0;
        for(int j = 0; j < m; j++){
            suma += array2d[i][j];
        }
        std::cout << "El total de la suma de la fila " << i << " es: " << suma << std::endl;
    }
}

int find_maxvalue(int ** array2d, int n, int m){
    int max = array2d[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(array2d[i][j] > max){
                 max = array2d[i][j];
            }
        }
    }
    return max;
}

int ** CrearNMatriz(int **array2d, int n, int m){
    int ** Transponer = new int*[m];
    for(int i = 0; i < m; i++){
        Transponer[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){ 
            Transponer[j][i] = array2d[i][j];
        }
    }
    return Transponer;
}

int main(){
    int n, m;
    std::cout << "Por favor ingrese los siguientes valores: ";
    std::cout << "Filas: "; std::cin >> n;
    std::cout << "Columnas: "; std::cin >> m;

   
    int ** MtrizD = new int*[n];
    for(int i = 0; i < n; i++){ 
        MtrizD[i] = new int[m];
    }

    std::cout << "Ingrese los valores:\n";
    for(int i = 0; i < n ; i++){ 
        for(int j = 0; j < m; j++){
             std::cout << "Posicion en la matriz:" << "[" << i << "]" << "[" << j << "]";
             std::cin >> MtrizD[i][j];
        }
    }

    plusfilas(MtrizD, n, m);
    std::cout << "El mayor elemento es: " << find_maxvalue(MtrizD, n, m) << std::endl;

    int ** trans = CrearNMatriz(MtrizD, n, m);

    std::cout << "Matriz transpuesta:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << trans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
