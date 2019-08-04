#include <bits/stdc++.h>
using namespace std;
string add(string s1,string s2)
{
    char a='0';
    int p=0,t;
    if(s1.length()<s2.length())
    {
       string temp=s1;
       s1=s2;
       s2=temp;
    }
    while(s2.length()<s1.length())
    {
       s2.insert(0,"0",1);
    }   
    
    string result="";                                            
    for(int i=s1.length()-1; i>=0  ;i--)
    { 
         
        t= (int)(s1[i]-'0') + (int)(s2[i] -'0') + p;
        p=t/10;
        t=t%10;
        result.push_back((char) (t + (int)a )) ;
     }
     if(p==1) result.push_back('1');
      
      reverse(result.begin(), result.end());
     return result;
}
string mul1(string s, char a)
{ 
    int k=(int)(a-'0');
   
    int p=0,t; 
    string result="";
    for(int i=s.length()-1; i>=0  ;i--)
    { 
         
        t= ((int)(s[i]-'0'))*k + p;
        p=t/10;
        t=t%10;
        result.push_back((char) (t + (int)('0'))) ;
        
     }
     if(p!=0)(result.push_back((char) (p + (int)('0'))) ) ;
     reverse(result.begin(), result.end());
     
     return result;
 }
    
int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string res="0";
    for(int i=s2.length()-1; i>=0  ;i--)
    {
         string mul=mul1(s1,s2[i]);
         mul.append((s2.length()-1-i),'0'); 
         res= add(res,mul);
    }
    cout<<res<<endl;
  }
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
