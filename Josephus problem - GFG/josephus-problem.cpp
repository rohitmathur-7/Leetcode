// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    void solve(int n,int k,vector<int>& arr,int idx){
        if(arr.size()==1) return;
        int er=(idx+(k-1))%arr.size();
        arr.erase(arr.begin()+er);
        solve(n,k,arr,er);
    }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           arr[i]=i+1;
       }
       solve(n,k,arr,0);
       return arr[0];
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends