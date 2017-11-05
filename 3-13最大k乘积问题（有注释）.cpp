// 3-13���k�˻�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int n, k;
string I;
int f[101][101];
int conv(int i, int j) {

	string str1 = I.substr(i, j);
	return atoi(str1.c_str());
}
void solve(int n, int m) {
	int i, j, k;
	int temp, maxt, tk;
	for (i = 1; i <= n; i++)//���֮�ֳ�һ�֣��ǵȸ�������
		f[i][1] = conv(0, i);


	for (j = 2; j <= m; j++) {//j��ʾ�ֵĶ�����j��2��ʼ
		for (i = j; i <= n; i++) {//i��ʾ�ַ���ǰi��

			for (k = 1, temp = 0; k<i; k++) {//k����ȥѰ���������и�
				/*
				����j=2,i=4��
				1   0   0
				12   2   0
				123  36   6
				1234 492 144
				k��1��ʼ��k<i;
				k=1ʱ��maxt=f[k][j-1]*conv(k,i-k)=f[1][1]*conv(1,1)=1*2=2;
				k=2ʱ��maxt=f[k][j-1]*conv(k,i-k)=f[2][1]*conv(2,1)=12*3=6;
				k=3ʱ��maxt=f[k][j-1]*conv(k,i-k)=f[1][1]*conv(3,1)=123*4=492;
				�����ķŵ�temp��
				*/
				maxt = f[k][j - 1] * conv(k, i - k);
				if (temp<maxt) { temp = maxt; }
			}
			f[i][j] = temp;
		}
	}
}

int main() {

	cin >> n >> k;
	cin >> I;
	if (n<k || n == 0 || n != I.size()) {
		cout << "0" << endl;
		return 0;
	}
	solve(n, k);
	printf("%d\n",f[n][k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			printf("%4d", f[i][j]);
		}
		cout << endl;
	}

}
