#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;
const int n = 3;
//---------------------------------------------------------
//列主元高斯消去
//打印数组
void printarray(double a[n][n], double b[n]);
//寻找最大列主元
int findColumnMax(double a[n][n], int j);
//换行，保持最大列主元在对角线
void swapline(int line, double a[n][n], int k, double b[n]);
//列主元高斯消去
void gaussin(double a[n][n], double b[n]);
//-----------------------------------------------------



