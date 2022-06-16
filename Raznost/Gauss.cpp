#include <iostream>
#include "Gauss.h"
#pragma once

void DV(double* a[], double b[], int N)
{
	for (int k = 1; k <= N; k++)
	{
		for (int j = k + 1; j <= N; j++)
		{
			double d = a[j][k] / a[k][k];
			for (int i = k; i <= N; i++)
			{
				a[j][i] = a[j][i] - (d * a[k][i]);
			}
			b[j] = b[j] - (d * b[k]);
		}
	}
}

void reverse(double* a[], double b[], double x[], int N)
{
	for (int k = N; k >= 1; k--)
	{
		double d = 0.0;
		for (int j = k + 1.0; j <= N; j++)
		{
			double s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (b[k] - d) / a[k][k];
	}
}
#pragma once
