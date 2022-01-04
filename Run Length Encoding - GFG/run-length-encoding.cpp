// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here
  char ch=s[0];int n=1;
  string ans;
  if(s.size()==1){
    ans+=ch;
    ans+=char(48+n); 
  }
  else{
      for(int i=1;i<s.size();i++){
          if(s[i]!=s[i-1]){
              ans+=ch;
              ans+=char(48+n);
              ch=s[i];
              n=1;
              if(i==s.size()-1){
                ans+=ch;
                ans+=char(48+n);  
              }
          }
          else{
              n++;
              if(i==s.size()-1){
                ans+=ch;
                ans+=char(48+n);
              }
          }
      }
  }
  return ans;
}     
 
