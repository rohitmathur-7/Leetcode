class Solution {
public:
    void solve(vector<int> arr,int factVal[],int n,int k,string& ans){
        if(n==1){
            ans+=to_string(arr[0]);
            return;   
        }
        int idx=(k/factVal[n-1]);
        if((k%factVal[n-1])==0) idx--;
        ans+=to_string(arr[idx]);
        arr.erase(arr.begin()+idx);
        k=k-(factVal[n-1]*idx);
        solve(arr,factVal,n-1,k,ans);        
        return;
    }
    string getPermutation(int n, int k) {
        int factVal[10]={1,1,2,6,24,120,720,5040,40320,362880};
        vector<int> arr;
        for(int i=0;i<n;i++) arr.push_back(i+1);
        string ans;
        solve(arr,factVal,n,k,ans);
        return ans;
    }
};