#include"numerical analysis.h"


using namespace std;


void printarray(double a[n][n], double b[n])
{
	vector<double>dvec;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dvec.push_back(a[i][j]);
		}
		dvec.push_back(b[i]);
	}
	
	for (vector<double>::iterator dit = dvec.begin();
		dit != dvec.end(); dit++)
	{	
		cout.width(15);
		cout << *dit << " ";
		cnt++;
		if (cnt % (n+1) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

int findColumnMax(double a[n][n],int j)
{
	double max=0.0;
	int line = 0;
	

	for (int i = j; i < n ; i++)
	{
		//以对角线上的值为基准，判断当前行向下的每一行中当前列最大值
		if (a[i][j] > max)
		{
			max = a[i][j];
			line = i;
		}		
	}
	cout << "当前最前列的最大值：" << max << " 第" << line + 1 << "行" << endl;
	return line;
}

void swapline(int line, double a[n][n],int k,double b[n])
{
	//k为消元次数,在这个函数中可代表当前系数矩阵的第一行
	if (line == k)
	{
		cout << "当前行已经为最大值，不需要转换" << endl;
		cout << "------------------------------------"<<endl;
		return;//如果当前行已经为最大值，不需要转换
	}
	double t[n][n] = { 0 };
	double tb = 0;

	tb = b[k];
	b[k] = b[line];
	b[line] = tb;

	for (int j = 0; j < n ; j++)
	{
		t[k][j] = a[k][j];
		a[k][j] = a[line][j];
		a[line][j] = t[k][j];

	}
	printarray(a, b);
	cout << "------------------------------------"<<endl;
}

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
