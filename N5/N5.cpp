//Численноевычесление с помощью формулы правых прямоугольников

#include <iostream>
#include <vector>

using namespace std;

double F(double x)
{
	return x * x * x;
}
double RightSquer1(double a, double b, int N)
{
	if (a > b)
	{
		swap(a, b);
	}
	double I = 0;
	double x = a;
	double h = (b - a) / N;
	
	for (int i = 0; i < N; i++)
	{
		I += F(x + h) * h;
		x += h;
	}
	return I;

}
double RightSquer2(vector<double> x)
{
	double I = 0;

	for (int i = 0; i < x.size() - 1; i++)
	{
		I += F(x[i + 1]) * ((x[i + 1] - x[i]));
	}
	return I;

}
int main()
{
	cout << RightSquer1(0, 1, 0.1) << endl;
	cout << RightSquer2({ 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 });

	return 0;
}