//Не работает
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

double operator*(vector<double> lhs, vector<double> rhs)
{
	double res = 0;

	for (int i = 0; i < lhs.size(); i++)
	{
		res += lhs[i] * rhs[i];
	}
	return res;
}
vector<double> operator*(vector<vector<double>> lhs, vector<double> rhs)
{
	vector<double> res(rhs.size());

	for (int i = 0; i < rhs.size(); i++)
	{
		for (int j = 0; j < rhs.size(); j++)
		{
			res[i] = lhs[i][j] * rhs[j];
		}
	}
	return res;
}
vector<double> operator+(vector<double> lhs, vector<double> rhs)
{
	vector<double> res(lhs.size());

	for (int i = 0; i < lhs.size(); i++)
	{
		res[i] = lhs[i] + rhs[i];
	}
	return res;
}
vector<double> operator*(vector<double> lhs, double rhs)
{
	vector<double> res(lhs.size());

	for (int i = 0; i < res.size(); i++)
	{
		res[i] = lhs[i] * rhs;
	}
	return res;
}
vector<double> operator*(double lhs, vector<double> rhs)
{
	return rhs * lhs;
}
vector<double> operator-(vector<double> lhs, vector<double> rhs)
{
	return lhs + (-1) * rhs;
}
double ABS(vector<double> vector)
{
	double t = 0;

	for (int i = 0; i < vector.size(); i++)
	{
		t += vector[i] * vector[i];
	}
	return sqrt(t);
}
vector<double> MinimalNevyazki(vector<vector<double>> a, vector<double> b, vector<double> x0, double epsilon)
{
	int N = x0.size();
	double accuracy;

	do
	{
		vector<double> y = a * x0 + b;
		vector<double> ay = a * y;
		double t = (y * ay) / (ay * ay);
		
		cout << t << endl;

		x0 = x0 - t * y;
		accuracy = ABS(y) / ABS(b);

		for (auto& i : x0)
		{
			cout << i << " ";
		}
		cout << endl;
		_getch();

	} while (accuracy > epsilon);

	return x0;
}
int main()
{
	vector<double> res = MinimalNevyazki(
		{ {1, 2, 3},
		{4, 5, 7},
		{7, 8, 9} },
		{ 1, 3, 4 },
		{ 0, 0, 0 },
		0.00001
	);

	for (auto& i : res)
	{
		cout << i << endl;
	}
}