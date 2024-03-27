#include <iostream>
#include <vector>

using namespace std;

unsigned long long Fact(int n)
{
	unsigned long long res = 1;

	for (int i = 0; i < n; i++)
	{
		res *= i;
	}
	return res;
}
double NewtonInterpolation1(double x0, double* u, double* x, int N)
{
	vector<vector<double>> U({ vector<double>(u, u + N) });

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
int main() 
{
	cout << NewtonInterpolation(2, { 1, 9, 16, 25, 36 }, { 1, 3, 4, 5, 6 }) << endl;
}