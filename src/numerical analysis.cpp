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
		//�ԶԽ����ϵ�ֵΪ��׼���жϵ�ǰ�����µ�ÿһ���е�ǰ�����ֵ
		if (a[i][j] > max)
		{
			max = a[i][j];
			line = i;
		}
	}
	cout << "��ǰ��ǰ�е����ֵ��" << max << " ��" << line + 1 << "��" << endl;
	return line;
}

void swapline(int line, double a[n][n], int k, double b[n])
{
	//kΪ��Ԫ����,����������пɴ���ǰϵ������ĵ�һ��
	if (line == k)
	{
		cout << "��ǰ���Ѿ�Ϊ���ֵ������Ҫת��" << endl;
		cout << "------------------------------------" << endl;
		return;//�����ǰ���Ѿ�Ϊ���ֵ������Ҫת��
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