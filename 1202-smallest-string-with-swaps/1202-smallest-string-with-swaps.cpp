class Solution {
public:
    int find(vector<int> &par,int a){
        if(par[a]==-1) return a;
        return find(par,par[a]);
    }
    void Union(vector<int>& par,vector<int>& rank,int a,int b){
        int x=find(par,a);
        int y=find(par,b);
        if(x==y) return;
        
        if(rank[x]>=rank[y]){
            par[y]=x;
            rank[x]++;
        }
        else{
            par[x]=y;
            rank[y]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int> par(n,-1);
        vector<int> rank(n,0);
        
        for(int i=0;i<pairs.size();i++){
            Union(par,rank,pairs[i][0],pairs[i][1]);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[find(par,i)].push_back(i);
        }
        
        for(auto x:mp){
            string tmp;
            for(auto y:x.second){
                tmp+=s[y];
            }
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<tmp.size();i++){
                s[x.second[i]]=tmp[i];
            }
        }
        
        return  s;
    }
};