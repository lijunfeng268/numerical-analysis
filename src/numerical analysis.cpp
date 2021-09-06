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
		if (cnt % (n + 1) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

int findColumnMax(double a[n][n], int j)
{
	double max = 0.0;
	int line = 0;


	for (int i = j; i < n; i++)
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

void swapline(int line, double a[n][n], int k, double b[n])
{
	//k为消元次数,在这个函数中可代表当前系数矩阵的第一行
	if (line == k)
	{
		cout << "当前行已经为最大值，不需要转换" << endl;
		cout << "------------------------------------" << endl;
		return;//如果当前行已经为最大值，不需要转换
	}
	double t[n][n] = { 0 };
	double tb = 0;

	tb = b[k];
	b[k] = b[line];
	b[line] = tb;

	for (int j = 0; j < n; j++)
	{
		t[k][j] = a[k][j];
		a[k][j] = a[line][j];
		a[line][j] = t[k][j];

	}
	printarray(a, b);
	cout << "------------------------------------" << endl;
}

void printarray(double a[n][n])
{
	vector<double>dvec;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dvec.push_back(a[i][j]);
		}
	}

	for (vector<double>::iterator dit = dvec.begin();
		dit != dvec.end(); dit++)
	{
		cout.width(8);
		cout << *dit << " ";
		cnt++;
		if (cnt % (n) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void printarray(double a[n])
{
	vector<double>dvec;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		
			dvec.push_back(a[i]);
	}

	for (vector<double>::iterator dit = dvec.begin();
		dit != dvec.end(); dit++)
	{
		cout.width(8);
		cout << *dit << " ";
		cnt++;
		if (cnt % (n) == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}