#include <bits/stdc++.h>
using namespace std;

const int M = 1<<17;

int tree[2*M];

void insert(int a, int v)
{
	a+=M;
	while(a>=1)
	{
		tree[a]+=v;
		a/=2;
	}
}

int query(int a, int b)
{
	int res = 0;
	a+=M; b+=M;
	while(a<=b)
	{
		if(a%2==1) res+=tree[a++];
		if(b%2==0) res+=tree[b--];
		a/=2; b/=2;
	}
	return res;
}

int n, m, a, b, c, q;

int main()
{
	cin>>n>>q;
	for(int i = 0; i < q; ++i)
	{
		cin>>c>>a>>b;
		if(c == 0)
		{
			insert(a, b);
		}
		else
		{
			cout<<query(a, b)<<"\n";
		}
	}
	return 0;
}
