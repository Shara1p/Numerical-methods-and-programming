#include <iostream>
#include "Gauss.h"
#include <math.h>



double F(double x) {
    return (-cos(x) + (((-1.0 + cos(1)) / sin(1)) * sin(x)) + 1) * (-2.0);
}

double F2(double x) {
	return (x * x / 2) + x;
}

double sh(double x) {
	return (exp(x) - exp(-x)) / 2;
}

double F3(double x) {
	return (sh(x) / sh(1) - 2*x) *(-1);
}

double F4(double x) {
	return x + exp(-x) - exp(-1);
}

double F5(double x) {
	return exp(x) - 2;
}


int main() {

	int N, i, j, k;
	std::cout << " N = ";
	std::cin >> N;
	double h = 1.0 / N;
	double** a = new double* [N];
	for (i = 0; i <= N; i++)
		a[i] = new double[N];
	double* b = new double[N];
	double* x = new double[N];


	
	 //ЗАДАЧА 1
	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			a[i][j] = 0.0;
		}
	}
	for (i = 2; i <= N; i++)
	{
		a[i][i] = 1.0 - (2.0 / (h * h));
		a[i][i - 1] = 1.0 / (h * h);
		a[i][i + 1] = 1.0 / (h * h);		
	}
	a[1][1] = 1.0;
	a[N][N] = 1.0;


	for (i = 2; i <= N; i++)
	{
		b[i] = 1.0;
	}
	b[1] = 0.0;
	b[N] = 0.0;
	*/


	// ЗАДАЧА 2
	/*for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			a[i][j] = 0.0;
		}
	}
	for (i = 2; i <= N; i++)
	{
		a[i][i] = -(2.0 / (h * h));
		a[i][i - 1] = 1.0 / (h * h);
		a[i][i + 1] = 1.0 / (h * h);
	}
	a[1][1] = 1.0;
	a[N][N] = 1.0;
	//a[N][N - 1] = 0.0;*/
	

	// ЗАДАЧА 3

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			a[i][j] = 0.0;
		}
	}
	for (i = 2; i <= N; i++)
	{
		a[i][i] = -1 -(2.0 / (h * h));
		a[i][i - 1] = 1.0 / (h * h);
		a[i][i + 1] = 1.0 / (h * h);
	}
	a[1][1] = 1.0;
	a[N][N] = 1.0;
	a[N][N - 1] = 0.0;

	// ЗАДАЧА 4
	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			a[i][j] = 0.0;
		}
	}
	for (i = 2; i <= N; i++)
	{
		a[i][i] = - (2.0 / (h * h));
		a[i][i - 1] = (1.0 / 2*(h * h)) -1/2*h ;
		a[i][i + 1] = (1.0 / (h * h)) + 1 / 2 * h;
	}
	a[1][1] = 1.0;
	a[N][N] = 1.0;
	//a[N][N - 1] = 0.0;
	*/

	// ЗАДАЧА 5
	/*
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			a[i][j] = 0.0;
		}
	}
	for (i = 2; i <= N; i++)
	{
		a[i][i] = -(2.0 / (h * h));
		a[i][i - 1] = (1.0 / 2 * (h * h)) + 1 / 2 * h;
		a[i][i + 1] = (1.0 / (h * h)) - 1 / 2 * h;
	}
	a[1][1] = 1.0;
	a[N][N] = 1.0;
	*/

	for (i = 2; i <= N; i++)
	{
		b[i] = 2*h*i;
	}
	b[1] = 0.0;
	b[N] = -1;
	

	//вывод матриц
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			std::cout << " " << a[i][j] << "\t";
		}
		std::cout << "|" << "\t" << b[i];
		std::cout << std::endl;
	}

	DV(a, b, N);
	reverse(a, b, x, N);

	std::cout << std::endl << " result: " << std::endl;
	for (i = 1; i <= N; i++)
		std::cout << " x[" << i << "] = " << x[i] << "\t F(x[" <<i << "]) =" << F3(x[i]) << "\t " << std::abs(F3(x[i]) - x[i]) << std::endl;

	return 0;
}
