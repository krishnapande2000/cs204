#include<bits/stdc++.h>
using namespace std;
int ismatch(string exp)
{
	stack<char> s;
   for(int i=0;i<exp.length();i++)
   {
   	  if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(' || exp[i]=='<' )
   	  	s.push(exp[i]);
   	  if(exp[i]=='|')
   	  {
   	  	if(s.empty() || s.top()!='|') { s.push(exp[i]); continue;}
   	  }

      if(s.empty()) return 0;
      if(exp[i]=='|')
   	  {
   	  	if(s.top()=='|') s.pop();
   	  }
   	  else
   	  {
   	  	switch(exp[i])
   	  	{
   	  		case '}':
   	  		if(s.top()!='{') return 0;
            else s.pop(); 
            break;
            case ']':
   	  		if(s.top()!='[') return 0;
            else s.pop(); 
            break;
            case ')':
   	  		if(s.top()!='(') return 0;
            else s.pop(); 
            break;
            case '>':
   	  		if(s.top()!='<') return 0;
            else s.pop(); 
            break;

   	  	}
   	  }

   }
   if(s.empty()) return 1;
   else return 0;
}
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
	  string s;
	  cin>>s;
	  if(ismatch(s)) cout<<"YES"<<endl;
	  else cout<<"NO"<<endl;
    }
	return 0;
}