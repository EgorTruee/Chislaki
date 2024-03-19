#include <iostream>
#include <vector>

using namespace std;

double F(double x)
{
	return x * x * x;
}
double Trapezoid1(double a, double b, int N)
{
	if (a > b)
	{
		swap(a, b);
	}
	double I = 0;
	double x = a;
	double f = F(x);
	double h = (b - a) / N;

	for (int i = 0; i < N; i++)
	{
		x += h;
		double t =F(x);

		I += (f + t) * h / 2;
		f = t;
	}
	return I;
}
double Trapezoid2(vector<double> x)
{
	double I = 0;
	double f = F(x[0]);

	for (int i = 0; i < x.size() - 1; i++)
	{
		double t = F(x[i + 1]);

		I += (f + t) / 2 * (x[i + 1] - x[i]);
		f = t;
	}
	return I;
}
int main()
{
	cout << Trapezoid1(0, 1, 0.1) << endl;
	cout << Trapezoid2({ 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 });

	return 0;
}