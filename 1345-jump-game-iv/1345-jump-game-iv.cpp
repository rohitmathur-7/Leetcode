class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int> > m;
        bool vis[n];
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
            vis[i]=false;
        }
        queue<int> q;
        q.push(0);
        int ans=0;
        vis[0]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int j=0;j<sz;j++){
                int i=q.front();q.pop();
                if(i==n-1) return ans;
                vector<int>& next=m[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(int x:next){
                    if(x>=0 && x<n && !vis[x]){
                        q.push(x);
                        vis[x]=true;
                    }
                }
                next.clear();
            }
            ans++;
        }
        return 0;
    }
};