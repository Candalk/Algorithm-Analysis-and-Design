// ������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#define n 6
int p[7]={30,35,15,5,10,20,25};
int m[7][7]={0};
/*

���i=j,m[i][j]=0;
���i<j,�Ǿ�Ҫȥ�Ҷϵ��λ��
����m[i][j]=min{m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]}����i=<k<j

*/
int main(){
	for(int i=1;i<=n;i++)m[i][i]=0;
	for(int r=2;r<=n;r++){//r��ʾ���������ĸ������Ӷ���ʼ
		for(int i=1;i<=n-r+1;i++){//i��ʾ���������ʼ���±�
			int j=i+r-1;//j��ʾ���������Ľ����±�
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			/*
			�տ�ʼ�ڵ�i���Ͽ�,��������Ӧ����m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
			����m[i][i]=0,��������д����m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			*/
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
				}
			
			}
		
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%6d ",m[i][j]);
		}
		cout<<endl;
	}
}
