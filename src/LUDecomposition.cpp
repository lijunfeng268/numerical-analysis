#include"numerical analysis.h"


using namespace std;

//1、要求AX=B
//2、A=LU求出L与U矩阵 则LUX=B
//3、LY=B 求出Y
//4、LUX=LY 则UX=Y 可求出X

void ALU(double a[n][n], double b[n])
{
	double u[n][n] = { 0 };
	double l[n] [n] = { 0 };
	//步骤二
	//对U矩阵的第一行赋值=A矩阵第一行
	for (int j = 0; j < n; j++)
	{
		u[0][j] = a[0][j];
	}
	//对L矩阵对角线赋值为1
	for (int i = 0; i < n; i++)
	{
		l[i][i] = 1;
	}
	//对L矩阵第一列赋值=A矩阵第一列/U矩阵u[0][0]
	for (int i = 1; i < n; i++)
	{
		l[i][0] = a[i][0] / u[0][0];
	}
	//printarray(l);
	//printarray(u);
	//求U矩阵第二行u[1][1]、u[1][2]-求L矩阵第二列L[2][1]-求U矩阵U第三行
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			double sum = 0;
			for (int k = 0; k < i; k++)
			{
				sum += l[i][k] * u[k][j];
			}
			u[i][j] = sum - a[i][j];
		}

	}
}