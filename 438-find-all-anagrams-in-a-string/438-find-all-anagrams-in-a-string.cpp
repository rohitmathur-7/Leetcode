class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        vector<int> ans;
        if(p.size()>s.size()) return ans;
        int l=p.size();
        map<char,int> m;
        for(int i=0;i<l;i++){
            m[p[i]]++;
        }
        map<char,int> m1;
        for(int i=0;i<=(s.size()-l);i++){
            if(i>0){
                // cout<<"i: "<<i<<endl;
                bool g=true;
                m1[s[i-1]]--;
                m1[s[i+l-1]]++;
                for(auto x:m){
                    // cout<<x.first<<" "<<x.second<<" "<<m1[x.first]<<endl;
                    if(m1[x.first]>x.second || m1[x.first]<x.second) g=false;
                }
                if(g) ans.push_back(i);
            }
            else{
                bool g=true;
                for(int j=i;j<i+l;j++){
                    m1[s[j]]++;
                    if(!m[s[j]]){
                        g=false;
                    }
                    if(m1[s[j]]>m[s[j]]){
                        g=false;
                    }
                }
                if(g) ans.push_back(i);
            }
        }
        return ans;
    }
};