#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
typedef set<int> si;


#define PB push_back
#define for(i,a,b) for(int i=a;i<=b;i++)
#define MP make_pair

ll search(vl list, ll n)
{
	ll u=list.size();
	ll d=0;

	ll mid = (u+d)/2;
    if(list[0]==n) return 0;
	while(mid>0)
	{
		if(list[mid]==n ) return mid;
		else if(list[mid]<n)
		{
			d=mid+1;
		}
		else 
		{
			u=mid-1;
		}
		mid=(u+d)/2;

	}
	return -1;

}

int main()
{
	vl op,us,rs,tus;
	ll n,q;
    vl disus;
	cin>>n>>q;
	for(i,0,q-1)
	{
		ll o; cin>>o;
		op.PB(o);
		
		if(op[i]==1)
		{
		   
			ll u,r;
			cin>>u>>r;
			us.PB(u);
			tus.PB(u);
			rs.PB(r);
			
		}
		else 
		{
			us.PB(-1);
			rs.PB(-1);
				
		}

	}
    
	sort(tus.begin(),tus.end());
	disus.PB(tus[0]);
	for(i,1,tus.size()-1)
	{
		if(tus[i]==tus[i-1]) continue;
		else
		{
			disus.PB(tus[i]);
			
		}

	}

	vl val(disus.size(),0);
    ll mi=-1,mv=-1;
	for(i,0,q-1)
	{

		
		if(op[i]==1)
		{
			ll temp=search(disus,us[i]);
			val[temp]+=rs[i];
			if(mv<val[temp])
			{
				mv=val[temp];
				mi=temp;
			}
			

		}
		else
		{
			if(mv==-1) cout<<"No data available"<<endl;
			else cout<<disus[mi]<<endl;

		}
	}


}