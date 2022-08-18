class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto x:arr) mp[x]++;
        
        vector<int> v;
        for(auto x:mp) v.push_back(x.second);
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        int ans=0;
        int n=arr.size();
        int tmp=n;
        for(int i=0;i<v.size();i++){
            tmp-=v[i];
            ans++;
            if(tmp<=n/2) break;
        }
        
        return ans;
    }
};