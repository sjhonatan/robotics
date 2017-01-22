#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;

int main()
{
	MatrixXd R(3,3);
	R << 1, 0, 0,
		 0, 0, -1,
		 0, 1, 0;
	cout << R;	
}
