/*
You are given input of employee information, which includes 
the employee's unique id, his importance value and his number direct subordinates' id.
Now given the employee information of a company, and an employee id, you need to return 
the total importance value of this employee and all his subordinates.

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
//int sum=0;

int dfs(int x,vi arr[],int imp[],int visited[])
{
	int sum;
	sum=imp[x];
	visited[x]=1;
	for(auto i:arr[x])
	{
		if(visited[i]==0)
		{
			sum+=dfs(i,arr,imp,visited);
		}
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	vi arr[n];
	int imp[n];
	int visited[n]={0};
	int x,im,nj;
	forr(i,0,n-1)
	{
		cin>>x>>imp[x]>>nj;
		forr(j,0,nj-1)
		{
			int t;
			cin>>t;
			arr[x].pb(t);
		}
	}
	int te;
	cin>>te;
    int sum=dfs(te,arr,imp,visited);
    cout<<sum<<endl;



}
