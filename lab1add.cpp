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
    }
    while(s2.length()<s1.length())
    {
       s2.insert(0,"0",1);
    }   
    
    char result[s1.length()+1];
    result[s1.length()]='\0';
    for(int i=s1.length()-1; i>=0  ;i--)
    { 
         
        t= (int)(s1[i]-'0') + (int)(s2[i] -'0') + p;
        p=0;
        if(t>=10)
        {
            p=1;
            t-=10;
        }
        result[s1.length()-i-1]=(char) (t + (int)a ) ;
     }
     if(p==1) result[s1.length()]='1';
     for(int i=0;i<=s1.length();i++)
        cout<<result[s1.length()-i];
     cout<<endl;   
     
     return 0;
}   
           
        
         
        
       

