//Union-find�؍\����c++�Ŏ���
//���ۂɎg���Ƃ��͊֐��ɕύX�������Ȃ��Ƃ����Ȃ����Ƃ�����܂�
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
int par[MAX_N];
int rank[MAX_N];
//�v���g�^�C�v
void init(int n);
int find(int x);
void unite(int x,int y);
bool same(int x,int y);
//n�v�f�ŏ�����
void init(int n)
{
	for (int i=0;i<n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
}
//�؂̍������߂�
int find(int x)
{
	if (par[x]==x)
	{
		return x;
	} else {
		return par[x]=find(par[x]);
	}
}
//x��y�̑�����W���𕹍�
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y) return;

	if (rank[x]<rank[y])
	{
		par[x]=y;
	} else {
		par[y]=x;
		if (rank[x]==rank[y]) rank[x]++;
	}
}
//x��y�������W���ɑ����邩�ۂ�
bool same(int x,int y)
{
	return find(x)==find(y);
}
