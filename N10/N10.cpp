#include <iostream>
#include <vector>

using namespace std;

void Gaus1(double** system, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double c = system[j][i] / system[i][i];

			for (int k = i + 1; k < n + 1; k++)
			{
				system[j][k] = system[j][k] - c * system[i][k];
			}
		}
	}
	vector<double> res(n);

	for (int i = n - 1; i >= 0; i--)
	{
		double sum = 0;
		
		for (int j = i + 1; j < n; j++)
		{
			sum += system[i][j] * res[j];
		}
		res[i] = (system[i][n] - sum) / system[i][i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << endl;
	}
}
vector<double> Gause(vector<vector<double>> system)
{
	int n = system.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double c = system[j][i] / system[i][i];

			for (int k = i + 1; k < n + 1; k++)
			{
				system[j][k] = system[j][k] - c * system[i][k];
			}
		}
	}
	vector<double> res(n);

	for (int i = n - 1; i >= 0; i--)
	{
		double sum = 0;
		
		for (int j = i + 1; j < n; j++)
		{
			sum += system[i][j] * res[j];
		}
		res[i] = (system[i][n] - sum) / system[i][i];
	}
	return res;
}
int main()
{
	vector<double> res = Gause({ {1, 2, 2},
		{2, 3, 1} });

	for (auto i : res)
	{
		cout << i << endl;
	}
	return 0;
}