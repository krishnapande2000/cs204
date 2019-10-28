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
	int n,m,eve=0;
	cin>>n>>m;
	vi v[n+m];
	forr(i,0,m-1){
		int a,b,x;
		cin>>a>>b>>x;
		if(x%2==1)
		{	
			v[a].pb(b);
			v[b].pb(a);
		}
		else
		{
			v[a].pb(n+eve);
			v[n+eve].pb(a);

			v[b].pb(n+eve);
			v[n+eve].pb(b);

			eve++;
		}

	}
	n=n+eve;
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
    	cout<<"YES\n";
    else
    	cout<<"NO\n";

}