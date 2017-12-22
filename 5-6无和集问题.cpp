// 5-6�޺ͼ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>  
#define N 100  
int F[N][N], answer[N][N];//F���ڴ�ȡ��ʱ���ݣ�answer���ڴ�ȡ���ս��
int n, maxValue;
bool judge(int k, int t) {
	for (int i = 1; i <= F[k][0]; i++) {
		for (int j = i + 1; j <= F[k][0]; j++) {
			if (F[k][i] + F[k][j] == t)return false;
		}
	}
	return true;
}
void DFS(int t) {

	if (t > maxValue) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j <= F[i][0]; j++) //F[i][0]��ȡF[i]�е����ݵĸ�������ʼֵΪ0;
				answer[i][j] = F[i][j];
		maxValue = t;
	}

	for (int i = 0; i < n; i++) {
		F[i][F[i][0] + 1] = t;
		if (judge(i,t)) {//�ж�t�Ƿ���Է���F[i]�����У�������ԷŽ�ȥ�� ���������������
			F[i][0] += 1;//��t�Ž�F[i]������
			DFS(t + 1);
			F[i][0] -= 1;//�����ٰ�t��F[i]������ȡ����
		}
	}
}
int main() {
	scanf("%d", &n);
	maxValue = 0;
	DFS(1);
	/*
	DFS(1)  F[0][0]=0;����������F[0][1]=1, F[0][0]++;	t++
	DFS(2)	F[0][0]=1;����������F[0][2]=2,	F[0][0]++;	t++
	DFS(3)	F[0][0]=2;������������F[1][0]=0,F[1][1]=3;F[1][0]++; t++;
	DFS(4)  ���������������ݳ��ԣ��ҵ�k�������
	��������
	DFS(9)	F[0],F[1]��������
	*/

	printf("%d\n", maxValue - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <=answer[i][0]; j++)
			printf("%d ", answer[i][j]);
		printf("\n");
	}

	return 0;
}


