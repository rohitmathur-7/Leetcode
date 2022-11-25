//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int N)
    {   
        // Your code here
        unordered_map<int, int> presum;
 
        int sum = 0;
        int max_len = 0;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum == 0){
                max_len = i + 1;
                for(int j=0;j<=i;j++){
                    ans.push_back(arr[j]);
                }
            }
            if(presum.find(sum) != presum.end()){
                if((i-presum[sum])>max_len){
                    max_len = i - presum[sum];
                    ans.clear();
                    for(int j=presum[sum]+1;j<=i;j++){
                        ans.push_back(arr[j]);
                    }
                }
            }
            else {
                presum[sum] = i;
            }
        }
    
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends