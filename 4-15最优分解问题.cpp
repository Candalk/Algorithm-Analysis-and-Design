#include<iostream>
using namespace std;
int k=1;
void dicomp(int n,int a[]){
	/*1,2�������������������Խ������0*/
	if(n<3){a[1]=0;return;}
	/*����3��4��ֻ������1��n-1*/
	if(n<5){a[k]=1;a[++k]=n-1;return;}
	/*���a+bΪһ���������|a-b|ԽС��a*bԽ��*/
	a[1]=2;n-=2;
	/*
		��2��ʼ���䣬��������ֱ�������Է���Ϊֹ
	*/
	while(n>a[k]){
		k++;
		a[k]=a[k-1]+1;
		n-=a[k];
	}
	//��Ϊ������Ҫ��ʣ���nƽ�����������
	//���n=a[k]���һ�����Ѷ����һ������������һ������
	if(n==a[k]){
		a[k]++;n--;
	}
	for(int i=0;i<n;i++)a[k-i]++;
}
int main(){

	int a[10];
	int n,sum=1;
	cin>>n;
	dicomp(n,a);
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=k;i++){
		sum*=a[i];
	}
	cout<<"max Multiply = "<<sum;
}