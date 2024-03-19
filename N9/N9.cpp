#include <iostream>

using namespace std;

double F(double x)
{
	return 1 / (1 + x * x);
}
double Integral(double a, double b, int N)
{
	if (a > b)
	{
		swap(a, b);
	}
	double x = a;
	double I = 0;
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
double AccuracyOrder(double a, double b, int N)
{
	int r = 2;
	int p = 2;
	double IN = Integral(a, b, N);
	double IrN = Integral(a, b, r * N);
	double IrrN = Integral(a, b, r * r * N);
	double RrN = (IrN - IN) / (pow(r, p) - 1);
	double RrrN = (IrrN - IrN) / (pow(r, p) - 1);

	return log(RrN / RrrN) / log(r);
}
int main()
{
	cout << Integral(-1, 1, 2) << endl;
	cout << AccuracyOrder(-1, 1, 2) << endl;
}