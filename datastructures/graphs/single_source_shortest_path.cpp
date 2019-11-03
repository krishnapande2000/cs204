/*

Single source shortest pair 
****BELLMAN-FORD ALGO****
****DP :  It first calculates the shortest distances which have at-most one edge in the path.
Then, it calculates shortest paths with at-most 2 edges, and so on.
After the i-th iteration of outer loop, the shortest paths with at most i edges are calculated.
There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times.
Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src.
If there is a negative weight cycle, then shortest distances are not calculated,
negative weight cycle is reported.


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
	int d[n];
	forr(i,0,m-1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v.pb({c,{a,b}});
		//arr[b].pb(a);

	}

	int src;
	cin>>src;

	forr(i,0,n-1)
	{
		d[i]=INT_MAX;

	}	
	d[src]=0;
	int change=0;
	//sort(v.begin(),v.end()); //to take min edge first
	forr(i,0,n-1)
	{
		forr(j,0,m-1)
		{
			change=0;
			int st=v[j].second.first;
			int e=v[j].second.second;
			int wt=v[j].first;
			if(d[st]!=INT_MAX && d[st] + wt < d[e])
			{
				d[e]=d[st]+wt;
				change=1;
			}


		}
	}

	if(change==1){
		cout<<"negative cycle"<<endl;

	}
	else{
		forr(j,0,n-1)
		{
			cout<<j<<" "<<d[j]<<endl;
		}
	}


}

/*
Input: 
8 10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
1
Output:
Min distance from 1 to 0 is: 2147483647
Min distance from 1 to 1 is: 0
Min distance from 1 to 2 is: 1
Min distance from 1 to 3 is: 3
Min distance from 1 to 4 is: 5
Min distance from 1 to 5 is: 0
Min distance from 1 to 6 is: 4
Min distance from 1 to 7 is: 3


*/