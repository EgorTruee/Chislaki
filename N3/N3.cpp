//Решение нелинейного уравнения с помощю метода Ньютона
//Уравнение вида f(x) = 0

#include <iostream>

using namespace std;

double F(double x)
{
	return x * x + x * x * x + 1;
}
double dFdx(double x)
{
	return 2 * x + 3 * x * x;
}
double NewtonMethod(double x0, double epsilon)
{
	double x1 = x0 - F(x0) / dFdx(x0);
	double x2 = x1 - F(x1) / dFdx(x1);
	double x3 = x2 - F(x2) / dFdx(x2);

	while (abs((x3 - x2) / (1 - (x3 - x2) / (x2 - x1))) > epsilon)
	{
		x1 = x2;
		x2 = x3;
		x3 = x3 - F(x3) / dFdx(x3);
	}
	return x3;
}
int main()
{
	cout << NewtonMethod(-1, 0.0000001) << endl;

	return 0;
}