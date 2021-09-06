#include"numerical analysis.h"


using namespace std;

//1��Ҫ��AX=B
//2��A=LU���L��U���� ��LUX=B
//3��LY=B ���Y
//4��LUX=LY ��UX=Y �����X

void ALU(double a[n][n], double b[n])
{
	double u[n][n] = { 0 };
	double l[n][n] = { 0 };
	//�����
	//��U����ĵ�һ�и�ֵ=A�����һ��
	for (int j = 0; j < n; j++)
	{
		u[0][j] = a[0][j];
	}
	//��L����Խ��߸�ֵΪ1
	for (int i = 0; i < n; i++)
	{
		l[i][i] = 1;
	}
	//��L�����һ�и�ֵ=A�����һ��/U����u[0][0]
	for (int i = 1; i < n; i++)
	{
		l[i][0] = a[i][0] / u[0][0];
	}
	printarray(l);
	printarray(u);
	//��U����ڶ���u[1][1]��u[1][2]-��L����ڶ���L[2][1]-��U����U������
	for (int i = 1; i < n; i++)
	{
		//��u�ڶ���
		for (int j = i; j < n; j++)
		{
			double sum1 = 0;
			for (int k = 0; k < i; k++)
			{
				sum1 += l[i][k] * u[k][j];
			}
			u[i][j] = a[i][j]-sum1;
			//printarray(u);
		}
		//��l�ڶ���
		for (int j = i + 1; j < n; j++)
		{
			double sum2 = 0;
			for (int k = 0; k < i; k++)
			{
				sum2 += l[j][k] * u[k][i];
			}
			l[j][i] = (a[j][i] - sum2) / u[i][i];
		}
		//printarray(u);
		//printarray(l);
	}
	//3��LY = B ���Y
	double y[n] = { 0 };
	y[0] = b[0];
	for (int i = 1; i < n; i++)
	{
		double sum3 = 0;
		for (int j = 0; j < n; j++)
		{
			sum3 += l[i][j] * y[j];
		}
		y[i] = b[i] - sum3;
	}
	printarray(y);

	//4��LUX=LY ��UX=Y �����X
	double x[n] = { 0 };
	x[n - 1] = y[n - 1] / u[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		double sum4 = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum4 += u[i][j] * x[j];
		}
		x[i] = (y[i] - sum4) / u[i][i];
	}
	printarray(x);
	return;
}