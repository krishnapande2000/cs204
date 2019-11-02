/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes 
(with distinct values 1, 2, ..., N), with one additional edge added. 
The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
Return an edge that can be removed so that the resulting graph is a tree of N nodes
input: 
n (number of nodes)
n lines with edges in pairs of int from 0 to n-1.
output:
redundant edge in a pair of int
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;


#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

ll frev(ll x,ll y)
{
	return x>y;
}

int findset(int a,int ds[],int rank[])
{
	if(a==ds[a]) return a;
	ds[a]=findset(ds[a],ds,rank);
	return ds[a];
}

int dsu(int a, int b,int ds[],int rank[])
{
	if(findset(a,ds,rank)==findset(b,ds,rank)) return 0; //findset of both is same . redundant edge
	int repa=findset(a,ds,rank);
	int repb=findset(b,ds,rank);
	if(rank[repa]==rank[repb])
	{
		rank[repb]++;
		ds[repa]=repb; //link
	}
	if(rank[repa]>rank[repb])
	{
		ds[repb]=repa; //link
	}
	else 
	{
		ds[repa]=repb; //link
	}
	return 1;
}
int main(){

	int n;
	cin>>n;
	
	int ds[n];
	int rank[n];

	forr(i,0,n-1)
	{
		ds[i]=i;//makesets each their own rep
		rank[i]=0;
	}
	int a,b;
	forr(i,0,n-1)
	{

		cin>>a>>b;
		int flag= dsu(a,b,ds,rank); //union of each being joined.
		if(flag==0)
		{
			cout<<a<<" "<<b<<endl;
			return 0;
		}
		

	}
	
}
