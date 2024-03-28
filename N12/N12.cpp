//Программа вроде работает по крайней мере все программы по невязкам работают по этому алгоритму
//
//Для компиляции необходимо скачать и собрать(собирать обязательно несмотря на то что пишут разрабы в гайде) библиотеку Eigen и записать 
//путь до неё в переменноой которая определяется в LocalConfig.cmake
#include <iostream>
#include <Eigen\Dense>
#include <conio.h>

using namespace std;
using namespace Eigen;

VectorXd MinNevyazki(MatrixXd a, VectorXd b, VectorXd x0, double epsilon)
{
	int i = 0;

	while ((a * x0 - b).norm() / b.norm() > epsilon && i < 100000)
	{
		VectorXd y = a * x0 - b;
		VectorXd ay = a * y;
		double t = (y.dot(ay)) / (ay.dot(ay));

		x0 -= t * y;
		i++;
	}
	return x0;
}
int main()
{
	MatrixXd m(2, 2);
	VectorXd v(2);
	VectorXd x0(2);

	m(0, 0) = 1;
	m(1, 0) = 2;
	m(0, 1) = 3;
	m(1, 1) = 4;
	v(0) = 1;
	v(1) = 2;
	x0(0) = 1;
	x0(1) = 1;

	cout << MinNevyazki(m, v, x0, 0.00001);
}