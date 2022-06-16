#include <iostream>
#include "Gauss.h"
#include <math.h>

double test(double x){
    return -cos(x) + (((-1.0 +cos(1.0))/sin(1.0))*sin(x)) + 1.0 ;
}


int main() {

    const int n = 4;
    double a = 0.0;
    double b = 1.0;
    double h = 1.0/n;

    double **matrix = new double*[n] ;

    for(int i = 0; i <  n; i++){
        matrix[i] = new double[n + 1];
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0.0;
        }
    }
    matrix[0][0] = 1.0;

    for(int i = 1; i <= (n - 1); i++){
        matrix[i][i] = 1.0 - (2.0/(h*h));
        matrix[i][i-1] = 1.0/(h*h);
        matrix[i][i+1] = 1.0/(h*h);
    }
    matrix[n-1][n-1] = 1.0;

    double *free = new double[n];
    free[0] = 0.0;
    free[n] = 0.0;
    for(int i = 1; i < (n-1); i++){
        free[i] = 1.0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    double *xs = new double[n];

    Gauss(free, n, matrix, xs);
    std::cout << std::endl;
    for(int i = 1; i <= n; i++){
        std::cout <<"x[" << i << "] = " << xs[i] << " | test = " << test(xs[i]) << std::endl;
    }




}
