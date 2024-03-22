#include <iostream>
#include <vector>

using namespace std;

vector<double> Progonka(vector<double> a, vector<double> b, vector<double> c, vector<double> d)
{
	int N = d.size();
	vector<double> epsilon(N);
	vector<double> etta(N);

	epsilon[0] = -c[0] / b[0];
	etta[0] = d[0] / b[0];

	for (int i = 1; i < N; i++)
	{
		epsilon[i] = -c[i] / (b[i] + a[i] * epsilon[i - 1]);
		etta[i] = (-a[i] * etta[i - 1] + d[i]) / (b[i] + a[i] * epsilon[i - 1]);
	}
	for (int i = 0; i < N; i++)
	{
		cout << i << " epsilon " << epsilon[i] << "\t\tetta " << etta[i] << "\t\ta " << a[i] << "\t\tb " << b[i] << "\t\tc " << c[i] << "\t\td " << d[i] << endl;
	}
	vector<double> res(N);
	
	res[N - 1] = etta[N - 1];

	for (int i = N - 2; i >= 0; i--) 
	{
		res[i] = res[i + 1] * epsilon[i] + etta[i];
	}
	return res;
}
int main()
{
	vector<double> solution = Progonka({ 0, 1, 2 },
		{ 3, 4, 5 },
		{ 6, 7, 0 },
		{ 1, 2, 3 });

	for (auto& i : solution)
	{
		cout << i << endl; //Maybe this go to gause
	}
}