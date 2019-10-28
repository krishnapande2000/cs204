#include<bits/stdc++.h>
using namespace std;


 
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
typedef set<int> si;
 
 
 
#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

int isbipartite=1;

int color_graph(int k,int color[],vi v[],int visited[])
{
	visited[k]=1;
	//cout<<"d";
	for(auto i:v[k])
	{

		if(color[i]==-1)
			{color[i]=1-(color[k]);
					}
	    else if(color[i]==color[k])
    	{
    		
    		isbipartite=0;
    		return 0;
    	}
	}
	for(auto i:v[k])
	{
		if(visited[i]==0)
		   color_graph(i,color,v,visited);
	}	
}

int main()
{
	int n,m;
	cin>>n>>m;
	vi v[n];
	forr(i,0,m-1){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int visited[n];
	forr(i,0,n-1)
	{
		visited[i]=0;
	}

	int color[n];
	forr(i,0,n-1)
	{
		color[i]=-1;
	}
    forr(i,0,n-1){
    	
    	if(color[i]==-1) 
    		{   color[i]=0;
    			color_graph(i,color,v,visited);
    		}
    	
    }

    if(isbipartite==0)
    	cout<<"NO\n";
    else
    	cout<<"YES\n";

}