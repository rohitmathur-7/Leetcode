// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        // your code here
        int mj=arr[0];
        int cnt=1;
        for(int i=1;i<size;i++){
            if(cnt==0){
                cnt=1;
                mj=arr[i];
            }    
            else if(arr[i]==mj) cnt++;
            else cnt--;
        }
        int c=0;
        for(int i=0;i<size;i++){
            if(arr[i]==mj) c++;
        }
        if(c>(size/2)) return mj;
        return -1;
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends