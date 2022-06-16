#include <iostream>
#include <cmath>

double f(double x){

    return tan(x) - x - 1;

}

int main() {

    std::cout << "f(0) = " << f(1) << std::endl;
    std::cout << "f(1.5) = " << f(1.5) << std::endl;

    double e = 0;
    double a = 0;
    double b = 0;
    std:: cout << "vvedite a" << std::endl;
    std::cin >> a;
    std:: cout << "vvedite b" << std::endl;
    std::cin >> b;
    std:: cout << "vvedite e" << std::endl;
    std::cin >> e;

    while(b - a > 2 * e){
        double c = ( a + b ) / 2;

        if(f(a) * f(c) > 0){
            a = c;
        } else{
            b = c;
        }
        std::cout << "[ " << a << "; " << b << "]" << std::endl;
    };

    std::cout << "Root value with accuracy of  " << e << " equals " << (a+b)/2 << std::endl;
    return 0;
}
