class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int ans=0;
	    unordered_map<int,int> m;
	    m[0]++;
	    int sum=0,rem;
        int N=arr.size();
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