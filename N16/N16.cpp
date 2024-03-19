#include <iostream>

using namespace std;

const double Ksi = (3 - sqrt(5)) / 2;

double F(double x)
{
	return (x - 1) * (x - 1);
}
double GoldenRatio(double a, double b, double epsilon)
{
	double x1 = a + (b - a) * Ksi;
	double x2 = b - (b - a) * Ksi;
	double f1 = F(x1);
	double f2 = F(x2);

	while (b - a > epsilon)
	{
		if (f2 > f1)
		{
			b = x2;
			x2 = x1;
			f2 = f1;
			x1 = a + (b - a) * Ksi;
			f1 = F(x1);
		}
		else
		{
			a = x1;
			x1 = x2;
			f1 = f2;
			x2 = b - (b - a) * Ksi;
			f2 = F(x2);
		}
	}
	return (a + b) / 2;
}
int main()
{
	cout << Ksi << endl;
	cout << GoldenRatio(0, 3, 0.000001) << endl;
}