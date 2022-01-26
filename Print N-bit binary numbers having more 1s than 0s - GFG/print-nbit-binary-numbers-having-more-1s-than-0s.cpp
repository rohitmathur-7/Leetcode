// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int one,int zero,string out,int tmp,int n,vector<string>& ans){
        if(tmp==n){
            ans.push_back(out);
            return;
        }   
        if(one>0){
            string out1=out;
            out1.push_back('1');
            solve(one-1,zero,out1,tmp+1,n,ans);
        }
        if(zero>one){
            string out2=out;
            out2.push_back('0');
            solve(one,zero-1,out2,tmp+1,n,ans);
        }
        return;
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int one=N,zero=N;
	    vector<string> ans;
	    string out="";
	    solve(one,zero,out,0,N,ans);
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends