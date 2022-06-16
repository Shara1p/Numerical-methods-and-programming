#include <iostream>
#include "Gauss.h"

double K(double,double ){
    return 0.0;
}

int main() {

    int N, i, j, k;
    int a,b;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << std::endl << "b = ";
    std::cin >> b;
    std::cout << std::endl <<  " N = ";
    std::cin >> N;
    double h = (b-a) / N;
    double** matrix = new double* [2*N + 2];
    for (i = 0; i <= N; i++){
        matrix[i] = new double[N];
    }

    double* t = new double[2*N + 2];
    double* x = new double[2*N + 2];
    double* A = new double[2*N + 2];

    for(int i = 1; i<2*N+1; i++){
        t[i] = (i-1)*h + a;
    }

    A[1] = h/3;

    for(int i = 1; i < N; i++){
        A[2*i] = (4*h)/3;
    }

    for(int i = 2; i < N; i++){
        A[2*i-1] = (2*h)/3;
    }

    for(int n = 1; n < 2*N+1; n++){
        for(int m = 1; m < 2*N+1; m++){
            matrix[n][m] = A[m] * K(t[n], t[m]);
        }
    }

}
