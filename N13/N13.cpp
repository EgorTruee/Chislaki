#include <iostream>
#include <vector>

using namespace std;

unsigned long long Fact(unsigned int n)
{
	static vector<unsigned long long> F = { 1, 1 };

	if (n < F.size())
	{
		return F[n];
	}
	else
	{
		for (int i = F.size(); i <= n; i++)
		{
			F.push_back(i * F[i - 1]);
		}
	}
	return F[n];
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

	for (int i = 0; i < N; i++)
	{
		double t = 1;

		for (int j = 0; j < i; j++)
		{
			t *= (x0 - x[j]);
		}
		res += U[i][0] / Fact(i) * t;
	}
	return res;
}
int main() 
{
	cout << NewtonInterpolation(2, { 1, 9, 16, 25, 36 }, { 1, 3, 4, 5, 6 }) << endl;
}