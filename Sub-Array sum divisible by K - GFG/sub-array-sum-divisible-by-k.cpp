// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long k)
	{
	    // Your code goes here
	    long long ans=0;
	    unordered_map<int,int> m;
	    m[0]++;
	    long long sum=0,rem;
	    for(int i=0;i<N;i++){
	        sum+=arr[i];
	        rem=sum%k;
	        if(rem<0) rem+=k;
	        ans+=m[rem];
	        m[rem]++;
	    }
	    return ans;
	}
};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends