#include"numerical analysis.h"


using namespace std;

void gaussin(double a[n][n], double b[n])
{
	
	double c[n] = {0};
	
	for (int k = 0; k < n - 1; k++)//进行n-1次消元操作
	{
		if (a[k][k] == 0)//计算中每次消元对角线上不能为0
		{
			cout << "a" << k+1 << k+1 << "=0，停止计算" << endl;
			return;
		}
		int line =findColumnMax(a, k);
		swapline(line, a, k,b);
		printarray(a, b);

		for (int i = k+1; i < n; i++)
		{
			//1.计算从第二行开始的每一行消元系数
			c[i] = a[i][k] / a[k][k];
		}
		for (int i = k + 1; i < n; i++)
		{
			//2.对第二行开始的每一行做消元
			for (int j = 0; j < n; j++)
			{
				a[i][j] -= c[i] * a[k][j];//更新系数矩阵
			}
			b[i] -= c[i] * b[k];
		}
		printarray(a, b);
	}
	
	double x[n];
	//计算最后一行x值
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	cout << "x"<<n<<"="<<x[n - 1]<<endl;

	for (int i = n - 2; i >= 0; i--)//从倒数第二行开始计算
	{
		double sum = 0;
		for (int j = i + 1; j < n; j++)
		{
			sum += a[i][j] * x[j];
			cout << "sum="<<sum << " ";
		}
		cout << endl;
		x[i] = (b[i] - sum) / a[i][i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << "=" << x[i] << endl;
	}
}
