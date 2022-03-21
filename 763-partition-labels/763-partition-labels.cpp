class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        vector<int> ans;
        int pos=0;
        while(pos<n){
            int mx=pos;
            int og_pos=pos;
            for(int i=pos;i<=m[s[pos]];i++){
                mx=max(mx,m[s[i]]);
            }
            int tmp;
            while(true){
                tmp=mx;
                for(int i=pos+1;i<=mx;i++){
                    mx=max(mx,m[s[i]]);
                }
                if(tmp==mx) break;
                pos=tmp+1;
            }
            ans.push_back(mx+1-og_pos);
            pos=mx+1;
        }
        
        return ans;
    }
};