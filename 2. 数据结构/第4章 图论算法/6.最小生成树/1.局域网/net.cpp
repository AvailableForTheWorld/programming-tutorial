#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int a[10001][3],fa[101];
int x,tot,k = 0;

int myfind(int poi);
void mysort(int l,int r);

int main()
{
	int i,j,n,m,ta,tb,mitot = 0,matot = 0;
	cin>>n>>m;
	for (i = 1;i <= m;i++)
	{
	   cin>>a[i][1]>>a[i][2]>>a[i][0];
	   matot += a[i][0];
	}
	for (i = 1;i <= n;i++)fa[i] = i;
	mysort(1,m);
	k = 0;
	for (i = 1;k != n - 1;i++)
	{
		ta = myfind(a[i][1]);
		tb = myfind(a[i][2]);
		if (ta != tb)
		{
			fa[tb] = ta;
			k++;
			mitot += a[i][0];
		}
	}
	cout<<matot - mitot<<endl;
	return 0;
}

int myfind(int poi)
{
	if (fa[poi] != poi) fa[poi] = myfind(fa[poi]);
	return fa[poi];
}

void mysort(int l,int r)
{
	int i,j,t,m;
	i = l;j = r;
	m = a[(l + r) / 2][0];
	do
	{
		while (a[i][0] < m) i++;
		while (a[j][0] > m) j--;
		if (i <= j)
		{
			t = a[i][1];a[i][1] = a[j][1];a[j][1] = t;
			t = a[i][2];a[i][2] = a[j][2];a[j][2] = t;
			t = a[i][0];a[i][0] = a[j][0];a[j][0] = t;
			i++;j--;
		}
	}
	while (i <= j);
	if (i < r) mysort(i,r);
	if (l < j) mysort(l,j);
	return;
}
