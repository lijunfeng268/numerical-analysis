#include"numerical analysis.h"

using namespace std;

int main()
{
	//����Ԫ��˹��ȥ ��ȷ�⣺x1=17.4593 x2=-45.76 x3=5.54604
	/*double a[n][n] = { 0.0120, 0.0100,  0.1670,
					   1.000,  0.8334,  5.910,
					   3200,   1200,    4.200, };
	double b[n] = { 0.6781,12.10,981.0 };
	gaussin(a, b);*/
	//----------------------------------------------------------
	
	double a[n][n] = {	1,2,-3,
						2,-1,3,
						3,-2,2 };
	double b[n] = { 1,5,1 };
	ALU(a, b);

	return 0;
}