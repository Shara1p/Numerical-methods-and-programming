#include <iostream>
#include "Gauss.h"

using namespace std;

double* Gauss(double *free, int n, double **matrix, double *&xs){

    int i;
    int j;
    double d = 0.0;
    double s = 0.0;
    int k;

//    double **a = new double *[n];
//
//    for (i = 0; i <= n; i++)
//
//        a[i] = new double [n];
//
//    double **a1 = new double *[n];
//
//    for (i = 0; i <= n; i++)
//
//        a1[i] = new double [n];
//
//    double *b = new double [n];
//

//
//    cout << "Input coefficients and free  members  " << endl;
//
//    for (i = 1; i <= n; i++)
//
//    {
//
//        for (j = 1; j <= n; j++)
//
//        {
//
//            cout << "a[" << i << "," << j << "]= ";
//
//            cin >> a[i][j];
//
//            a1[i][j] = a[i][j];
//
//        }
//
//        cout << "b[ " << i << "]= ";
//
//        cin >> b[i];
//
//    }

    for (k = 1; k <= n; k++) // прямой ход

    {

        for (j = k + 1; j < n; j++)

        {

            d = matrix[j][k] / matrix[k][k]; // формула (1)

            for (i = k; i <= n; i++)

            {

                matrix[j][i] = matrix[j][i] - d * matrix[k][i]; // формула (2)

            }

            free[j] = free[j] - d * free[k]; // формула (3)

        }

    }

    for (k = n-1; k >= 1; k--) // обратный ход

    {

        d = 0.0;

        for (j = k + 1; j <= n; j++)

        {

            s = matrix[k][j] * xs[j]; // формула (4)

            d = d + s; // формула (4)

        }

        xs[k] = (free[k] - d) / matrix[k][k]; // формула (4)

    }

    cout << "Root values: " << endl;

    for( i = 1; i <= n; i++){
        cout << "x[" << i << "]=" << xs[i] << " " << endl;
    }




    return 0;

}
