#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;

int main()
{
	MatrixXd Pborg(3,1);
	Pborg << 0, 
			 2,
			 0;
	cout << Pborg << endl;
	MatrixXd Pb(3,1);
	Pb << 2,
		  2,
		  2;
	cout << Pb << endl;
	cout << "\n\n Ponto final" << endl;
	MatrixXd Pa(3,1);
	Pa << Pborg + Pb;
	cout << Pa;
}
