#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y){
        return cos(x)/(y+2);
}

double F1(double x, double y){
    return sin(x)/(y+2);
}

int main() {
        double a = 0;
        double b = 1;
        double h = 0.1;

        double n = 10;
        double X[(int)n]; double Y[(int)n];

        X[0]=a; Y[0]=0;

        for(int i=1; i<=n; i++){
                X[i]=a+i*h;
                Y[i]=Y[i-1]+h*F(X[i-1],Y[i-1]);
        }
        for(int i=0; i<=n; i++){
                cout << "X["<<i<<"]="<<X[i] <<" " << "Y["<<i<<"]="<<Y[i] << std::endl;
        }

        return 0;
}
