class Solution {
public:
    
    void dfs(vector<int> &adj,vector<bool> &vis,int i,vector<pair<int,int>> &a,int c){
        a.push_back({i,c});
        vis[i]=true;
        if(adj[i]!=-1 && !vis[adj[i]]){
            dfs(adj,vis,adj[i],a,c+1);
        }
    }
    void dfs2(vector<int> &adj,vector<bool> &vis,int i,vector<pair<int,int>> &a,int c,unordered_map<int,int> &mp){
        a.push_back({i,c});
        // fs.push_back(i);
        mp[i]=c;
        vis[i]=true;
        if(adj[i]!=-1 && !vis[adj[i]]){
            dfs2(adj,vis,adj[i],a,c+1,mp);
        }
    }
    
    int closestMeetingNode(vector<int>& adj, int node1, int node2) {
        vector<pair<int,int>> a,b;
        vector<int> fs;
        int V=adj.size();
     
        vector<bool> vis(V,false);
        
        int c=0;
        dfs(adj,vis,node1,a,c);
        vis.assign(V,false);
        c=0;
        unordered_map<int,int> mp;
        dfs2(adj,vis,node2,b,c,mp);

        int mn=INT_MAX,d1,d2,d,ans=-1;            
        for(auto x:a){
            int pos;
            if(mp.count(x.first)){
                // pos=find(fs.begin(),fs.end(),x.first)-fs.begin();
                pos=mp[x.first];
                d1=x.second;
                d2=b[pos].second;
                d=max(d1,d2);
                //cout<<"xf: "<<x.first<<" xs: "<<x.second<<" "<<b[pos].second<<endl;               
                
                if(d<=mn){
                    if(ans==-1) ans=x.first;
                    else if(mn==d) ans=min(ans,x.first);
                    else ans=x.first;
                    mn=d;
                }
            }
        }
        
        return ans;
    }
};