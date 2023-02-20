#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 10000;
const double PI = acos(-1.0);

double S1[N], S2[N], S3[N], W[N], Am[N], x[N], y[N], h[N];
int Nx = 100, Ny1;

class Complex
{
	public:

		double re;
		double im;

		Complex operator + (Complex t)
		{
			t.re = t.re + re;
			t.im = t.im + im;
			return t;
		}
		
		Complex operator * (double t)
		{
			Complex tmp;
			tmp.re = t * re;
			tmp.im = t * im;
			return tmp;
		}

		Complex operator * (Complex t)
		{
			Complex tmp;
			tmp.re = t.re * re - t.im * im;
			tmp.im = t.re * im + t.im * re;
			return tmp;
		}			
};

void signal (double w, double S[])
{
	for (int n = 0; n <= Nx; ++n) 
	S[n] = n * cos(w * n) * exp(-n / 6.0);
}


void Amp (double Am[], double W[], int Nm, double x[], int Nx)
{
	for (int k = 0; k <= Nm; ++k)
	{
		W[k] = PI * k / Nm;
		Complex cAm[N] = {0};
		Complex Z, Zn;
		Z.re = cos(W[k]), Z.im = sin(W[k]); 
		Zn.re = Z.re, Zn.im = Z.im;
		for (int n = 0; n <= Nx; ++n)
		{
			if (n == 0)
			{
				Zn.re = 1;
				Zn.im = 0;
			}
		    else for (int i = 0; i < n - 1; i++) 
					Zn = Zn.operator * (Z);
			cAm[k] = cAm[k] + Zn * x[n];
			Zn.re = Z.re;
			Zn.im = Z.im;
		} 
		Am[k] = sqrt(pow(cAm[k].re, 2) + pow(cAm[k].im, 2));
	}
}

void DSINE (double h[], int Nh, double Wc1, double Wc2)
{
	h[0] = (Wc2 - Wc1) / PI;
	for (int n = 1; n <= Nh; ++n)
		h[n] = sin(Wc2 * n) / (PI * n) - sin(Wc1 * n) / (PI * n);
}

void CONV(double x[], int Nx, double h[], int Nh)
{
	for (int k = 0; k <= Nh; ++k)
	{
		for(int m = 0; m <= Nx; ++m)
		{
			int n = k + m;
			y[n] += h[k] * x[m];
		}
	}
}

int main()
{
	freopen("2.out","w",stdout);

	signal(0.2, S1);
	signal(1.3, S2);
	signal(2.5, S3);

	for (int i = 0; i <= Nx; ++i)
		x[i] = S1[i] + S2[i] + S3[i];

	cout << "x:\t";
	for (int i = 0; i <= Nx; ++i)
		cout << x[i] << "\t";
	cout << endl;

	Amp (Am, W, 100, x, 100);

	cout << endl;
	cout << "Amx:\t";
	for (int k = 0; k <= 100; ++k)
		cout << Am[k] << "\t";
	cout << endl;

	DSINE (h, 65, 0.8, 1.8);

	cout << endl;
	cout << "h:\t";
	for (int i = 0; i <= 65; ++i)
		cout << h[i] << "\t";
	cout << endl;

	Amp (Am, W, 100, h, 65);

	cout << endl;
	cout << "Amh:\t";
	for (int k = 0; k <= 100; ++k)
		cout << Am[k] << "\t";
	cout << endl;

	CONV (x, 100, h, 65);

	cout << endl;
	cout << "y:\t";
	for (int k = 0; k <= 100; ++k)
		cout << y[k] << "\t";
	cout << endl;

	Amp (Am, W, 100, y, 165);

	cout << endl;
	cout << "Amy:\t";
	for (int k = 0; k <= 100; ++k)
		cout << Am[k] << "\t";
	cout << endl;

	return 0;
}

