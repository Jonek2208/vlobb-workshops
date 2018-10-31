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

int n, m, a, b, c;

vector< pair<int, int> > g[N];
vector< pair<int, int> > mst[N];
vector< pair<int, pair<int, int> > > edges;

int p[N], r[N];

void Init()
{
	FOR(i, 1, n) p[i] = i;
}

int Find(int x)
{
	if(p[x] != x) p[x] = Find(p[x]);
	return p[x];	
	
	//~ return (p[x] == x ? x : p[x] = Find(p[x]));
}

bool Union(int x, int y)
{
	x = Find(x); y = Find(y);
	if(x == y) return false;
	//~ if((x = Find(x)) == (y = Find(y))) return;
	
	if(r[x] > r[y]) p[y] = x;
	else p[x] = y;
	if(r[x] == r[y]) ++r[y];
	return true;
}

int main()
{
	cin>>n>>m;
	
	REP(i, m)
	{
		cin>>a>>b>>c;
		g[a].PB(MP(b, c));
		g[b].PB(MP(a, c));
		edges.PB(MP(c, MP(a, b)));
	}
	
	Init();
	
	sort(edges.begin(), edges.end());
	int sum = 0;
	for(auto it: edges)
	{
		a = it.ND.ST;
		b = it.ND.ND;
		c = it.ST;
		
		if(Union(a, b))
		{
			sum+=c;
			mst[a].PB(MP(b, c));
			mst[b].PB(MP(a, c));
		}
	}
	
	cout<<sum<<"\n";
	FOR(i, 1, n)
	{
		cout<<i<<" : ";
		for(auto it: mst[i])
		{
			cout<<"("<<it.ST<<", "<<it.ND<<") ";
		}
		cout<<"\n";
	}
	
	//~ for(auto it: edges) cout<<it.ST<<" ("<<it.ND.ST<<", "<<it.ND.ND<<")\n";
	
	
	return 0;
}

/*
7 9
1 7 1
1 2 2
1 3 2
2 4 2
4 6 1
5 6 4
3 5 1
2 3 2
4 3 3


*/

