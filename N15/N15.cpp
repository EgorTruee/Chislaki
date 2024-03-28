#include <iostream>
#include <functional>
#include <vector>

using namespace std;

double Integral(vector<double> x, vector<double> u)
{
	double I = 0;

	for (int i = 1; i < u.size(); i++)
	{
		I += (u[i - 1] + u[i]) / 2 * (x[i] - x[i - 1]);
	}
	return I;
}
function<double(double)> Phi(unsigned int k)
{
	return [k](double x) {return pow(x, k); };
}
vector<double> Gaus(vector<vector<double>> a, vector<double> b)
{
	int N = a.size();

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double c = a[j][i] / a[i][i];

			b[j] -= c * b[i];	

			for (int k = i + 1; k < N; k++)
			{
				a[j][k] -= c * a[i][k];
			}
		}
	}
	vector<double> res(N);

	for (int i = N - 1; i >= 0; i--)
	{
		double Sum = 0;

		for (int j = i + 1; j < N; j++)
		{
			Sum += a[i][j] * res[j];
		}
		res[i] = (b[i] - Sum) / a[i][i];
	}
	return res;
}
vector<double> PolynomApproximation(int k, vector<double> x, vector<double> u)
{
	vector<vector<double>> A(k, vector<double>(k));
	vector<double> B(k);

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			vector<double> t(x.size());

			for (int b = 0; b < x.size(); b++)
			{
				t[b] = Phi(i)(x[b]) * Phi(j)(x[b]);
			}
			
			A[i][j] = Integral(x, t);
		}
		vector<double> UPhi(x.size());

		for(int j = 0; j < x.size(); j++)
		{
			UPhi[j] = u[j] * Phi(i)(x[j]);
		}
		B[i] = Integral(x, UPhi);
	}
	return Gaus(A, B);
}
vector<double> Approximation(vector<double> x, vector<double> u, vector<double> delta)
{
	double SqrDelta = 0;
	double k = 1;
	double SqrError = 0;
	vector<double> res;

	for (int i = 0; i < delta.size(); i++)
	{
		SqrDelta += delta[i] * delta[i];
	}

	do
	{
		res = PolynomApproximation(k, x, u);
		SqrError = 0;

		for (int i = 0; i < x.size(); i++)
		{
			double F = 0;

			for (int j = 0; j < res.size(); j++)
			{
				F += res[j] * Phi(j)(x[i]);
			}
			SqrError += (u[i] - F) * (u[i] - F);
		}
		k++;

	} while (SqrError > SqrDelta);

	return res;
}
int main()
{
	vector<double> res = Approximation({ 1, 2, 3, 4, 5 }, { -4, -1, 4, 11, 20 }, { 1, 1, 1, 1, 1 });
	double s = 0;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " * x^" << i << endl;
	}
	cout << endl;

	for (int i = 0; i < res.size(); i++)
	{
		s += res[i] * Phi(i)(6);
	}
	cout << s;
}