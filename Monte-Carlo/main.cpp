#include <iostream>
#include <cmath>


double f(double x){
    return x*sqrt(x + 1);
}

int random(int min, int max) //range : [min, max]
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

int main() {


    double a, b, x, h, s;
    int n;
    std::cout << "Input ends of interval" << std::endl;
    std::cin >> a >> b;
    std::cout << "Input N" << std::endl;
    std::cin >> n;
    h = (b-a)/n;
    s = 0;
    for(int i = 0; i <= n; i++ ){
        x = a +(b-a)*random(a,b);
        s += f(x)*h;
    }

    std::cout << "Value of integral = " << s << std::endl;

}
