#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;

int main()
{
	MatrixXd T(4,4);
	T << 1, 0, 0, 0,
			 0, 0, -1, 3,
			 0, 1,  0, 2,
			 0, 0,  0, 1;
	MatrixXd Pb(4,1);
	Pb << 0,
		  1,
		  1,
		  1;
	MatrixXd Pa(4,1);
	Pa << T * Pb;
	MatrixXd P(3,1);
	int i = 0;
	for(i = 0; i < 3; i++)
	{
		P(i) =  Pa(i);
	}
	cout << P;
}
