#include"numerical analysis.h"


using namespace std;

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
