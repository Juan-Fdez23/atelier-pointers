// Punto #3 (Lambdas + composicion de operadores)

#include <iostream>

double Realizar(double* arreglo, int x, auto transformarValor, auto combinarValores){
    double solve = 0;

    for(int i = 0; i < x ; i++){
        double ValorT = transformarValor(arreglo[i]);
        solve = combinarValores(solve, ValorT);
    }
    return solve;
}

auto transformarValor = [](double x) -> double{
    return x * 2;
};

auto combinarValores = [](double n1, double n2) {
    return n1 + n2;
};

int run(){
    int x = 7;

    double* arreglo = new double[x]{1 , 2 ,3 , 4, 5 , 6 ,7};

    double solve = Realizar(arreglo, x, transformarValor, combinarValores);

    std::cout << "Resultado final: " << solve << std::endl;

    delete[] arreglo;

    return 0;
}

int main(){
    run();
    return 0;
}
