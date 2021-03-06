// 2-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct node {
	string s;
	int count;
}S;
bool cmp(struct node a, struct node b) {
	return a.count>b.count;
}
int main()
{
	int n;
	S.count = 0;
	string s;
	cin >> n;
	vector<struct node> v(n, S);
	for (int i = 0; i<n; i++) {
		cin >> s;
		for (int j = 0; j<n; j++)
			if (v[j].s == s || v[j].count == 0) {
				v[j].count++;
				v[j].s = s;
				break;
			}
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) 
		if (v[i].count == v[0].count) 
			cout << v[i].s << " " << v[i].count<<endl;
	return 0;
}
