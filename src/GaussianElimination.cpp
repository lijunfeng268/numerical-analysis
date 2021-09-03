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

void swapline(int line, double a[n][n],int k,double b[n])
{
	//kΪ��Ԫ����,����������пɴ���ǰϵ������ĵ�һ��
	if (line == k)
	{
		cout << "��ǰ���Ѿ�Ϊ���ֵ������Ҫת��" << endl;
		cout << "------------------------------------"<<endl;
		return;//�����ǰ���Ѿ�Ϊ���ֵ������Ҫת��
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
	
	for (int k = 0; k < n - 1; k++)//����n-1����Ԫ����
	{
		if (a[k][k] == 0)//������ÿ����Ԫ�Խ����ϲ���Ϊ0
		{
			cout << "a" << k+1 << k+1 << "=0��ֹͣ����" << endl;
			return;
		}
		int line =findColumnMax(a, k);
		swapline(line, a, k,b);
		printarray(a, b);

		for (int i = k+1; i < n; i++)
		{
			//1.����ӵڶ��п�ʼ��ÿһ����Ԫϵ��
			c[i] = a[i][k] / a[k][k];
		}
		for (int i = k + 1; i < n; i++)
		{
			//2.�Եڶ��п�ʼ��ÿһ������Ԫ
			for (int j = 0; j < n; j++)
			{
				a[i][j] -= c[i] * a[k][j];//����ϵ������
			}
			b[i] -= c[i] * b[k];
		}
		printarray(a, b);
	}
	
	double x[n];
	//�������һ��xֵ
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	cout << "x"<<n<<"="<<x[n - 1]<<endl;

	for (int i = n - 2; i >= 0; i--)//�ӵ����ڶ��п�ʼ����
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
