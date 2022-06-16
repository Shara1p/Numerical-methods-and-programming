#include <iostream>
#include <cmath>

double f(double x) {
	return sqrt(4*sin(x));
}

int main()
{
	double e;
	e = 0.001;
	double x1 = 1;
	double x2 = f(x1);

	while (std::abs(x2 - x1) > e) {
		x1 = x2;
		x2 = f(x1);
        std::cout << "|x| = " << x1 << " |x1| = " << x2 << " |x1 - x| = " << std::abs(x2 - x1) << std::endl;
	}
    if(!(f(x2) == x2)){
        x2 *=-1;
    }
	std::cout << "Root value with accuracy of " << e << " equals " << x2 << std::endl;

}

