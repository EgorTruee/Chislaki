// Решение нелинейного уравнения методом дихотомии
// Решается уравнение вида f(x) = 0

#include <iostream>

using namespace std;

double f(double x)
{
	return x * x - 1;
}
double binFinding(double epsilon, double a, double b)
{
	if (b < a)
	{
		swap(a, b);
	}
	double c = (a + b) / 2;
	double fa = f(a);
	double fb = f(b);

	if (fa * fb > 0)
	{
		return 0;
	}
	while (b - a > 2 * epsilon)
	{
		c = (a + b) / 2;

		double fc = f(c);

		if (fc == 0)
		{
			return c;
		}
		else if (fc * fa > 0)
		{
			a = c;
		}
		else
		{
			b = c;
		}
	}
	return c;
}
int main()
{
	cout << binFinding(0.00001, 0, 4) << endl;

	return 0;
}
