#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
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
      cout<<result;
     cout<<endl;   
     
     return 0;
}   
