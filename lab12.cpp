/*
mailed by the name lab_11_04
max product spanning tree

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

int findset(int a,int ds[],int rank[])
{
    if(a==ds[a]) return a;
    ds[a]=findset(ds[a],ds,rank);
    return ds[a];
}

int dsu(int a, int b,int ds[],int rank[])
{
     
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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pii>> v;

    forr(i,0,m-1)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        v.pb({c,{a-1,b-1}});

    }
    sort(v.begin(),v.end()); //to take max edge first


    int ds[n];
    int rank[n];
    forr(i,0,n-1)
    {
        ds[i]=i;//makesets each their own rep
        rank[i]=0;
    }

    ll sum=1;

    for(int i=m-1;i>=0;i--)
    {
        int a=v[i].second.first;
        int b=v[i].second.second;
        if(findset(a,ds,rank)!=findset(b,ds,rank)) //if findset of both is same not in mst
        {
            dsu(a,b,ds,rank);
            sum=(sum*v[i].first)%1000000007;
        }

            
    }
    cout<<sum%1000000007<<endl;


    

    

}