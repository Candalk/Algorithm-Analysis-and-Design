// 3-3ʯ�Ӻϲ����⣨̰���㷨��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int N,minsum=0,maxsum=0;
	cin >> N;
	/*
	v1��������Ѱ����Сֵ
	v2��������Ѱ�����ֵ
	*/
	vector<int> v1(N),v2(N);
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
		v2[i] = v1[i];
	}
		/*
		��С�����v1��������
		ֻ�����С��
		*/
	sort(v1.begin(), v1.end());
	int i = 1;
	while (i < N) {
		int temp = v1[i-1] + v1[i];
		minsum += temp;
		v1[i] = temp;
		sort(v1.begin() + i, v1.end());
		i++;
	}
	printf("minsum = %d", minsum);

	/*
	��С�����v2��������
	ֻ�������
	*/
	sort(v2.begin(), v2.end(),cmp);
	 i = 1;
	while (i < N) {
		int temp = v2[i - 1] + v2[i];
		maxsum += temp;
		v2[i] = temp;
		sort(v2.begin() + i, v2.end(),cmp);
		i++;
	}
	printf("maxsum = %d", maxsum);
    return 0;
}

