class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        if(n==1) return 1;
        bool a[n+1];
        for(int i=1;i<=n;i++) a[i]=false;
        map<int,int> m;
        int nn=trust.size();
        for(int i=0;i<nn;i++){
            m[trust[i][1]]++;
            a[trust[i][0]]=true;
        }
        for(auto x:m){
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second==n-1 && !a[x.first]){
                return x.first;
            }
        }
        return -1;
    }
};