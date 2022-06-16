#include <iostream>

double f(double x) {
    return exp(0.72*x)*sin(1.44*x); // 5 вар 1/(sqrt(x*x+1.74 ))
}

int main()
{
   
    double a = 0;
    double b = 0;
    double x = 0;
    double h = 0;
    double s = 0;
    int i = 0;
    int n = 0;
    std::cout << "Write down ends of interval " << std::endl;
    std::cin >> a >> b;
    std::cout << "Write down n " << std::endl;
    std::cin >> n;
    h = (b - a) / n;
    s = (f(a) - f(b)) / 2;
    for (int i = 0; i < n / 2; i++) {
        x = a + 2 * i * h;
        s += f(x) + 2 * f(x - h);
    }
    s = s * 2 * h / 3;
    std::cout << "Value of integral equals " << s;


}

