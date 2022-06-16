#include <iostream>
#include <cmath>

double sec(double x){
    return 1/cos(x);
}

double f(double x) {
    return tan(0.5*x + 0.1) - pow(x,2);
}

double f1(double x) {
    return sec(pow(0.5*x + 0.1,2))/2 - pow(x,2);
}

double f11(double x){
    return (sin(0.5*x + 0.1)/(2*cos(pow(0.5*x + 0.1,3)))) - 2;
}
int main()
{


    std::cout << "Enter begin and end of the interval" << std::endl;
    double a;
    double b;
    std::cin >> a >> b;

    std::cout << "Enter accuracy" << std::endl;
    double e;
    e = pow(10,-7);



    double m;
    m = std::min(std::abs(f1(a)), std::abs(f1(b)));
    std::cout <<"m = " << m << std::endl;
    //std::cin >> m;


    double x = 0;
    if(f(a)*f11(a) > 0){
        x = a;
    }
    if ((f(b)*f11(b) > 0)) {
        x = b;
    }


    while ((std::abs(f(x)) / m) > e) {
        std::cout <<"x = " << x << "| " << "m = " << m << "| " << "|f(x)) / m)| = " << std::abs(f(x) / m) << std::endl;
        x = x - (f(x)/f1(x));
    }
    std::cout << "Root value with accuracy of " << e << " equals " << x << std::endl;
    std::cout << "f(x) = " << f(x);

}

