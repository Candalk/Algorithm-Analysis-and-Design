// 5-3��С���������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	struct node *right, *left;
};
vector<int> s1,S;
int n, c,depth=-1;
void print() {
	vector<int>::iterator it2 = s1.begin();
	while (it2 != s1.end()) {
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
/*
0-1�������⣬
������ȱ�����������depthΪ����������ȣ�
���Ҫ�������������Ͱѵ�ǰ���ֵS[depth]�Ž�ջs1�У�
����ֵ��ǰ�ڵ�Ϊ��һ�ڵ���ϵ�ǰ���ֵ����root->left->data=root->data+S[depth]
�����Ҫ���������������ѵ�ǰ���ֵ�Ž�ȥ��
����һ�ڵ��ֵ��ֵ����ǰ�ڵ㼴�ɣ���root->right->data=root->data;
*/
void DFS(node *root) {
	if (root->data == c)print();
	else if (root->data > c)return;
	if (depth < n-1) {
		depth++;
		root->left = new node;
		root->left->data = root->data + S[depth];
		s1.push_back(S[depth]);
		DFS(root->left);
		s1.pop_back();

		root->right = new node;
		root->right->data = root->data;
		DFS(root->right);
		depth--;
	}

}
int main()
{
	cin >> n >> c;
	S.resize(n+1);
	for (int i = 0; i < n; i++) cin >> S[i];
	node *root = new node;
	root->data = 0;
	root->left = root->right = NULL;
	DFS(root);
    return 0;
}

