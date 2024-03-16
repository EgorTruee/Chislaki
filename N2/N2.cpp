//Решение уравнения методом простой итерации
//уравненин вида f(x) = x

#include <iostream>

using namespace std;

double F(double x)
{
	return 0.25 * x + 1;
}
double SimpleIteration(double x0, double epsilon)
{
	double x1 = F(x0);
	double x2 = F(x1);
	double x3 = F(x2);

	while ((x3 - x2) / (1 - (x3 - x2) / (x2 - x1)) > epsilon)
	{
		x1 = x2;
		x2 = x3;
		x3 = F(x3);
	}
	return x3;
}
int main()
{
	cout << SimpleIteration(0, 0.000001) << endl;

	return 0;
}