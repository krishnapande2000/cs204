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

vector<string> str;


bool mycompare(string x,string y)
{
    string s1= x+y;
    string s2=y+x;

    for(i,0,s1.length()-1)
    {
         if(s1[i]>s2[i])
         {
            return true; 
         }
         if(s1[i]<s2[i])return false;   
    }
  
}

/*
void merge(vector<string> s, int l,int m,int r)
{
	vector<string> R,L;
	
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
   
  
    
    for (i ,0,n1) 
        L.PB(s[l + i]); 
    for (j,0,n2) 
        R.PB(s[m + 1+ j]); 

	int i = 0; // Initial index of first subarray 
     int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < L.size() && j < R.size() ) 
    { 
        if (mycompare(L[i],R[j]))
        { 
            s[k] = L[i]; 
            i++; 
        } 
        else
        { 
            s[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < L.size()) 
    { 
    	cout<<"in a while"<<endl;
        s[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < R.size()) 
    { 
    	cout<<"in a while 2"<<endl;
        s[k] = R[j]; 
        j++; 
        k++; 
    } 

}

void merge_sort(vector<string> s, int l,int r)
{

	cout<<"merge call"<<endl;
	if(l<r)
	{
		cout<<"merge call succeded "<<endl;
	int m= l+ (r-1)/2 ;
	merge_sort(s, l,m);
	merge_sort(s,m+1,r);
	merge(s,l,m,r);
}

} */

int main()
{
	int t;
	cin>>t;
	for(i,1,t)
	{
		int l;
		cin>>l;
		str.clear();
		for(i,0,l-1)
		{
			cout<<"for of main"<<endl;
			string s;
			cin>>s;
			str.PB(s);

		}
		sort(str.begin(),str.end(), mycompare);
		
		for(i,0,l-1)
		{
			cout<<str[i];
		}
		cout<<endl;
	}
	return 1;
	
}

















































































































































































































































































































































































































































































































































































































































































































































































































