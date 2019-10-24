#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;


#define pb push_back
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair

int maxc=0,maxi,maxj;
int m,n;
//vector<vector<int>> visited(m);



int isValid(int key,int i,int j, vector<vector<int>> &input ,vector<vector<int>> & visited )
{
	if(key==input[i][j] && visited[i][j]==0)
		return 1;
	else 
		return 0;

}

int bfs(int i,int j,vector<vector<int>> &input,int m,int n,vector<vector<int>> & visited)
{
	visited[i][j]=1;
	int c=1;
	if(1)
	{

		if(j+1<n && isValid(input[i][j],i,j+1,input,visited)  )
		{
			c+=bfs(i,j+1,input,m,n,visited);
		}
		if(j-1>=0 && isValid(input[i][j],i,j-1,input,visited)  )
		{
			c+=bfs(i,j-1,input,m,n,visited);
		}
		if(i+1<m && isValid(input[i][j],i+1,j,input,visited))
		{
			c+=bfs(i+1,j,input,m,n,visited);
		}
		if(i-1>=0 && isValid(input[i][j],i-1,j,input,visited))
		{
			c+=bfs(i-1,j,input,m,n,visited);
		}
	}
	return c;

}

int count_large(vector<vector<int>> &input,int m,int n,vector<vector<int>> & visited)
{
	int countc;
	forr(i,0,m-1)
	{
		forr(j,0,n-1)
		{
			countc=0;
			if(visited[i][j]==0)
            	countc=bfs(i,j,input,m,n,visited);
            if(countc > maxc )
            {
            	maxi=i;
            	maxj=j;
            	maxc=countc;

            }

		}
	}
}

int main()
{
	int c,x;
	cin>>m>>n>>c;
	vector<vector<int>> input(m);
	vector<vector<int>> visited(m);
	forr(i,0,m-1)
	{
		forr(j,0,n-1)
		{
			visited[i].pb(0);
		}
	}
    forr(i,0,m-1)
    {
    	forr(j,0,n-1)
    	{
    		cin>>x;
    		input[i].pb(x);
    	}
    }


    


    count_large(input,m,n,visited);
    cout<<maxc<<" "<<input[maxi][maxj]<<endl;
   

}