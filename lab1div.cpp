#include <bits/stdc++.h>
using namespace std;
string sub(string s1,string s2)
{
   char a='0';
    int p=0,t;
    if(s1.length()<s2.length())
    {
       string temp=s1;
       s1=s2;
       s2=temp;
       cout<<"-";
    }
  if(s1.length()==s2.length())
    {
       for(int i=0;i<s1.length();i++)
       {
          if(s1[i]>s2[i]) break;
          if(s1[i]<s2[i])
          {
          string temp=s1;
          s1=s2;
          s2=temp;
          cout<<"-";
          break;
          }
          }
    }
    while(s2.length()<s1.length())
    {
       s2.insert(0,"0",1);
    }   
    
    string result="";
    for(int i=s1.length()-1; i>=0  ;i--)
    { 
         
        t= (int)(s1[i]-'0') - (int)(s2[i] -'0') + p;
        p=0;
        if(t<0)
        {
            p=-1;
            t+=10;
        }
       result.push_back((char) (t + (int)a )) ;
     }
     
     reverse(result.begin(), result.end());
     result.erase(0, result.find_first_not_of('0'));
     if(result=="") result="0";
     return result;
 }
 
int com(string s1,string s2)
{
    int i;
   if(s1.length()>s2.length()) return 1;
   else if(s1.length()<s2.length()) return 0;
   else{
       for(i=0;i<s2.length();i++)
       {
           if(s1[i]>s2[i]) return 1;
           if(s2[i]>s1[i]) return 0;
       }
       return 2;
       }
}       
       
int main()
{
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string res="";
    int n1=s1.length();
    int n2=s2.length();
    if(com(s1,s2)==0){ cout<<0<<" "<<s1<<endl; return 0;}
    if(com(s1,s2)==2) {cout<<1<<" "<<0<<endl; return 0;}
    string x="";
    int j=n2-1,k=0;
    for(int i=0;i<n2;i++) x.push_back(s1[i]);
    
    while(j<n1)
    {
        
        k=0;
        while(com(x,s2)!=0)
        {
            x=sub(x,s2);
            k++;
        }
        j++;
        if(j<n1) x.push_back(s1[j]);
        x.erase(0, x.find_first_not_of('0'));
        if(x=="") x="0";
        res.push_back(k+'0');    
    }
    res.erase(0, res.find_first_not_of('0'));
    cout<<res<<" "<<x<<endl;
    return 0;
}    
             
            
    
   
    
    
