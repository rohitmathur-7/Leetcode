class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int> > adj(n);
        for(int i=0;i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int> indegree(n,0);
        for(auto x:adj){
            for(auto y:x){
                indegree[y]++;
            }
        }                
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int a=q.front();q.pop();
            cnt++;
            for(auto x:adj[a]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        
        if(cnt==n) return true;
        return false;
        
    }
};