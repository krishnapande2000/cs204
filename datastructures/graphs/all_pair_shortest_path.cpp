/*

All pair shortest path.
Given a graph with weighted edges find the shortest distance between each pair of vertices 
and print it in the form of a matrix.
FLOYD-WARSHELL ALGO:
DP is used . assuming we know the shortest 
input:
no of vertices, edges.

edges in source destination weight format

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef vector<pair<int,int>> vpii;
#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

ll frev(ll x,ll y)
{
	return x>y;
}




int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pii>> v;

	//vi arr[n];
	ll d[n][n];
	forr(j,0,n-1)
	{
		forr(i,0,n-1)
		{
			if(j==i) d[j][i]=0;
			else
				d[j][i] = INT_MAX ;
		}
	}
	forr(i,0,m-1)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		v.pb({c,{a,b}});
		//arr[b].pb(a);
		d[a][b]=c;

	}

	forr(k,0,n-1){
		forr(j,0,n-1){
			forr(i,0,n-1){

				if(d[j][i] > d[j][k] + d[k][i])
					d[j][i]=d[j][k] + d[k][i];
			}
		}
	}

	forr(j,0,n-1)
	{
		forr(i,0,n-1)
		{
			if(d[j][i]==INT_MAX)
				cout<<"inf"<<" ";
			else
				cout<<d[j][i]<<" ";
		}
		cout<<"\n";
	}

}

/*
input:

4 8
0 0 0
0 1 5
0 3 10 
1 1 0
1 2 3
2 2 0
2 3 1
3 3 0

output:

0 5 8 9 
inf 0 3 4 
inf inf 0 1 
inf inf inf 0 


*/