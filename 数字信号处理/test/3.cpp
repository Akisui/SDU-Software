#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10000;
const double PI = 3.14159265358979323846264338327950288;

double x[N], h[N], X[N], diff[N];
int Nx = 100;

double sinc (int x)
{
	if (x == 0) return 1;
	else return (sin(x) / x);
}

void REC (double X[], int Nx, int N1, int N2)
{
	for (int n = 1; n <= Nx; ++n)
	{
		if (n % N1 == 0) continue;
		int N3 = n / N1;
		for (int k = N3 - N2 + 1; k <= N3 + N2; ++k)
		{
			int Y = 1 + abs(n - k * N1);
			h[Y] = sinc((Y - 1) / N1);
			X[n] += x[k * N1] * h[Y];
		}
	}
}

int main()
{
	freopen("3.out","w",stdout);

	for (int i = 1; i <= Nx; ++i)
	{
		x[i] = i * exp((-1 * i) / 15) * cos(2 * PI * i / 16);
		if (i % 5 == 0) X[i] = x[i];
		else X[i] = 0;
	}

	REC(X, 100, 5, 6);

	for (int i = 1; i <= Nx; ++i)
		diff[i] = x[i] - X[i];

	cout << endl;
	cout << "x:\t";
	for(int i = 1; i <= Nx; ++i) 
		cout << x[i] << "\t";
	cout << endl;

	cout << endl;
	cout << "X:\t";
	for (int i = 1; i <= Nx; ++i)
		cout << X[i] << "\t";
	cout<<endl;

	cout << endl;
	cout << "diff:\t";
	for (int i = 1; i <= Nx; ++i)
		cout << diff[i] << "\t";
	cout << endl;

	return 0;
}
