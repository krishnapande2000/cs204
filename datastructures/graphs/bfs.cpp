/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<pair<int,int>> vpii;

#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

ll frev(ll x,ll y)
{
	return x>y;
}
//int sum=0;


int main(){
	int n,m,res=0;
	cin>>n>>m;
	int arr[n][m];
	vpii ones;
	int visited[n][m];
	forr(i,0,n-1)
	{
		forr(j,0,m-1){
			cin>>arr[i][j];
			if(arr[i][j]==1)
			{
				ones.pb(mp(i,j));
			}
			visited[i][j]=0;

		}
	}

	forr(i,0,ones.size())
	{
		vpii q;
		int x=ones[i].first;
		int y=ones[i].second;
		if(visited[x][y]==0)
		{
			res++;
			q.pb({x,y});

			while(!q.empty())
			{
				pi val=q.back();
				q.pop_back();
				int l=val.first,r=val.second;
				visited[l][r]=1;
				if(l-1>=0 && arr[l-1][r] && !visited[l-1][r]) q.pb({l-1,r});
				if(l+1<n && arr[l+1][r] && !visited[l+1][r]) q.pb({l+1,r});
				if(r-1>=0 && arr[l][r-1] && !visited[l][r-1]) q.pb({l,r-1});
				if(r+1<n && arr[l][r+1] && !visited[l][r+1]) q.pb({l,r+1});


			}
		}
	}
	cout<<res<<endl;
			

}

/*

3 3 
1 1 0
1 0 1
0 1 0

3

*/