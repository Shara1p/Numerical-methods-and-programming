#include <iostream>
#include <cmath>

double F(double x, double y){
    return cos(x)/(y+2);
}

double F1(double x, double y){
    return sin(x)/(y+2);
}

int main() {

    int n;
    double h;
    double X, Y, S, K1, K2, K3, K4;
    X = 0;
    Y = 0;
    n = 10;
    h = 0.1;
    for(int i = 0; i <= n; i++){
        std::cout <<"X" << " = " << X << std::endl;
        std::cout <<"Y" << " = " << Y << " F(x) = " <<F1(X,Y)  << std::endl;
        K1 = F(X,Y)*h;
        X += h/2;
        K2 = F(X,Y+K1/2)*h;
        K3 = F(X,Y+K2/2)*h;
        X += h/2;
        K4 = F(X,Y+K3)*h;
        Y += (K1 + 2*K2 + 2*K3 + K4)/6;
    }

}
