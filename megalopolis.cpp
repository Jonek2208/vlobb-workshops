#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = b; i <= e; ++i)
#define FORD(i, b, e) for(int i = b; i >= e; --i)
#define REP(i, n) FOR(i, 0, n-1)
#define REV(i, n) FORD(i, n-1, 0)
#define PB push_back
#define PP pop_back
#define ST first
#define ND second
#define MP make_pair

const int N = 300005;
const int M = 1<<17;

/*drzewo*/
int tree[2*M];

void insert(int a, int b, int v)
{
	a+=M; b+=M;
	while(a<=b)
	{
		if(a%2==1) tree[a++]+=v;
		if(b%2==0) tree[b--]+=v;
		a/=2; b/=2;
	}
}

int query(int a)
{
	int res = 0;
	a+=M;
	while(a>=1)
	{
		res+=tree[a];
		a/=2;
	}
	return res;
}

/*koniec drzewa*/

vector<int> g[N];
int rozm[N], pre[N], odl[N];

int n, m, a, b;

int cnt = 0, h = -1;

void DFS(int v, int u)
{
	odl[v] = ++h;
	pre[v] = ++cnt;
	rozm[v] = 1;
	
	for(auto w: g[v])
	{
		if(w != u)
		{
			DFS(w, v);
			rozm[v]+=rozm[w];
		}
	}
	
	--h;
}

int main()
{
	cin>>n;
	
	REP(i, n-1)
	{
		cin>>a>>b;
		g[a].PB(b);
		g[b].PB(a);
	}
	
	DFS(1, -1);
	
	cin>>m;
	
	char c;
	
	REP(x, n+m-1)
	{
		cin>>c;
		if(c == 'A')
		{
			cin>>a>>b;
			if(pre[a] > pre[b]) swap(a, b);
			insert(pre[b], pre[b]+rozm[b]-1, 1);
		}
		else
		{
			cin>>a;
			cout<<(odl[a] - query(pre[a]))<<"\n";
		}
	}
	
	return 0;
}

