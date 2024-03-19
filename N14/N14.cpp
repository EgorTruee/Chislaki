#include <iostream>
#include <vector>

using namespace std;

double NewtonInterpolation(double x0, vector<double> u, vector<double> x)
{
	vector<vector<double>> U({ u });
	int N = u.size();

	for (int i = 1; i < N; i++)
	{
		U.push_back(vector<double>(N - i));

		for (int j = 0; j < N - i; j++)
		{
			U[i][j] = i * (U[i - 1][j] - U[i - 1][j + 1]) / (x[j] - x[j + i]);
		}
	}
	double res = 0;
	unsigned long long Fact = 1;

	for (int i = 0; i < N; i++)
	{
		double t = 1;

		for (int j = 0; j < i; j++)
		{
			t *= (x0 - x[j]);
		}
		Fact = (i == 0 ? 1 : Fact * i);
		res += U[i][0] / Fact * t;
	}
	return res;
}
double F(double x)
{
	return x * x - 4;
}
double NewtonInterpolationMethod(vector<double> u, vector<double> x)
{
	return NewtonInterpolation(0, x, u);
}
int main()
{
	cout << NewtonInterpolationMethod({ -4, -1, 4, 11, 21 }, { 1, 2, 3, 4, 5 }) << endl;
}