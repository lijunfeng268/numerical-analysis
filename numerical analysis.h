#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int n = 3;
//---------------------------------------------------------
//����Ԫ��˹��ȥ
//��ӡ����
void printarray(double a[n][n], double b[n]);
//Ѱ���������Ԫ
int findColumnMax(double a[n][n], int j);
//���У������������Ԫ�ڶԽ���
void swapline(int line, double a[n][n], int k, double b[n]);
//����Ԫ��˹��ȥ
void gaussin(double a[n][n], double b[n]);
//-----------------------------------------------------



