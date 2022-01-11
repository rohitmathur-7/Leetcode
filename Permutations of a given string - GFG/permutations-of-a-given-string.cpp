// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void permutations(string s,int i,set<string> &st){
	        if(s[i]=='\0'){
	            st.insert(s);
	            return;
	        }
	        for(int j=i;s[j]!='\0';j++){
	            swap(s[j],s[i]);
	            permutations(s,i+1,st);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    set<string> st;
		    permutations(s,0,st);
		    vector<string> ans;
		    for(auto x:st){
		        ans.push_back(x);
		    }
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends