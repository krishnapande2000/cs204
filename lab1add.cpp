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
      cout<<result;
     cout<<endl;   
     
     return 0;
}   
           
        
         
        
       

