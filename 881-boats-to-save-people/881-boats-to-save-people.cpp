class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit){
        int n=arr.size();
        int a=0,b=n-1;
        int ans=0,cnt=0;
        sort(arr.begin(),arr.end());
        while(a<b){
            if((arr[a]+arr[b])<=limit){
                ans++;
                cnt+=2;
                a++;
                b--;
            }
            else{
                b--;
            }
        }
        ans+=(n-cnt);
        return ans;  
    }
};