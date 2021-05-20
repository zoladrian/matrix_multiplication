//program mnożący dwie macierze kwadratowe, zawierające dane typu double(generowane losowo) i pokazujący czas wykonania zadania.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <random>
using namespace std;

//funkcja generatora losowej liczby
unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
default_random_engine rd(seed);
uniform_real_distribution<double> liczba;
mt19937 gen;
int main()
{
    const int a = 1000;     //ilosc wierszy i kolumn

 //matryce dynamiczne
    double** MAT1 = new double* [a];
    double** MAT2 = new double* [a];
    double** MATW = new double* [a];
    int i, j, k;

    cout << endl << "Zapelniono pierwsza matryce liczbami: " << endl;
    for (i = 0; i < a; i++)
    {

        MAT1[i] = new double[a];
        for (j = 0; j < a; j++)
        {
            {
                MAT1[i][j] = liczba(rd);
                cout << MAT1[i][j] << endl;


            }

        }
    }
    cout << endl << "Zapelniono druga matryce liczbami: " << endl;
    for (i = 0; i < a; ++i)
    {

        MAT2[i] = new double[a];
        for (j = 0; j < a; ++j)
        {
            MAT2[i][j] = liczba(rd);
            cout << MAT2[i][j] << endl;
        }
    }
    // OBLICZENIA
    clock_t start, stop;
    double czas;
    start = clock();
    for (i = 0; i < a; i++)
    {

        for (j = 0; j < a; j++)
        {
            MAT1[i] = new double[a];
            MAT2[i] = new double[a];
            MATW[i] = new double[a];
            for (k = 0; k < a; k++)
            {
                MATW[i][j] += (MAT1[i][k] * MAT2[k][j]);

                cout << endl << endl << MATW[i][j] << endl;

            }
        }
    }
    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "mnozenie macierzy zajmie: " << czas << endl;
    return 0;
}

