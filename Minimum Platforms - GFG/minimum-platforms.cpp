// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	/*
    	    Think of this problem as a normal day to day problem,
    	    So what we will do is sort both arrival and departure arrays,
    	    you might wonder isn't it going to separate the indices of arrival and 
    	    departure?
    	    Yes it will do, but it actually dosen't matter,
    	    Because think of it this way, what we basically want is that when a train is arriving and when a train is leaving 
    	    So if some train has arrival time greater than the train with the least departure time then we can just use the same platform otherwise 
    	    we will use different platforms.
    	*/
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans=1;
    	int plat=1;
    	int i=1,j=0;
    	while(i<n && j<n){
    	    if(arr[i]>dep[j]){
    	        plat--;
    	        j++;
    	    }
    	    else{
    	        plat++;
    	        i++;
    	        ans=max(ans,plat);
    	    }
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends