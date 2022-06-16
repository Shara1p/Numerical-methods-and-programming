#include <iostream>
#include <cmath>

double f(double x){
    return sqrt(1+x)*log(x) - 2 ;
}

double f1(double x){

    return log(x-2)/(2*sqrt(x+1)) + sqrt(x+1)/(x-2);
}

double f11(double x){
    return -log(x-2)/(4*pow(x+1,1.5)) + 1/((x-2)*sqrt(x+1))-sqrt(x+1)/pow(x-2,2);
}

int main() {

    double e = 0.000001;

    std::cout << "Write down begin and end of the interval" << std::endl;
    double a = 0;
    double b = 0;
    std::cin >> a >> b;

    std::cout << "f(3) = "<<f(3) << std::endl;
    std::cout << "f(2.5) = " << f(2.5) << " f11(2.5) = " << f11(2.9) << std::endl;
    std::cout << "f(3.5) = " << f(3.5) << " f11(3.5) = " << f11(3.5) << std::endl;



    double m;
    m = std::min(std::abs(f1(a)), std::abs(f1(b)));
    std::cout <<"m = " << m << std::endl;

    double x;
    x = b;



    while(std::abs((a - f(a)/(f(x) - f(a))*(x-a)) - x) > e){

        x = a - f(a)/(f(x) - f(a))*(x-a);

    }

    std::cout << "Root value with accuracy of " << e << " equals " << x << std::endl;
    std::cout << "f(x) = " << round(f(x)) << std::endl;


}
