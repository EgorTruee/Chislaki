#include <iostream>

using namespace std;

double F(double x)
{
	return 1 / (1 + x * x);
}
double Integral(double a, double b, double N)
{
	if (a > b)
	{
		swap(a, b);
	}
	double I = 0;
	double x = a;
	double h = (b - a) / N;
	double f = F(x);

	for (int i = 0; i < N; i++)
	{
		x += h;
		
		double t = F(x);

		I += (f + t) / 2 * h;
		f = t;
	}
	return I;
}
double Error(double a, double b, int N)
{
	int r = 2;
	int p = 2;
	double IN = Integral(a, b, N);
	double IrN = Integral(a, b, r * N);

	return (IrN - IN) / (pow(r, p) - 1);
}
int main()
{
	cout << Integral(-1, 1, 4) << endl;
	cout << Error(-1, 1, 2) << endl;
}