// 4-9������������.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
7 7
1 2 3 4 5 1 6 6

7 7
1 9 2 3 4 5 3 2
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(k + 2);
	v[0] = 0;
	for (int i = 1; i < k + 2; i++)
		cin >> v[i];
	int temp = n,flag=0,num=0;
	for (int i = 0; i < k + 1; i++) {
		if (n < v[i + 1]) {//����������˻��޷�������һ����վ
			flag = 1;
			break;
		}
		if (temp >= v[i + 1])//��ǰ�����ܹ�������һ����վ
			temp = temp - v[i + 1];
		else {
			temp = n;
			temp = temp - v[i + 1];
			num++;
		}	
	}
	if (flag)printf("No Solution");
	else printf("%d", num);
    return 0;
}

