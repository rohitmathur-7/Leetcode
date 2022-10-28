class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        vector<pair<string,string> > v;
        for(int i=0;i<n;i++){
            pair<string,string> p;
            p.second=strs[i];
            sort(strs[i].begin(),strs[i].end());
            p.first=strs[i];
            v.push_back(p);
        }
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            vector<string> tmp;
            int pos=i+1;
            
            for(int j=pos;j<v.size();j++){
                if(v[j].first==v[j-1].first) pos++;
                else break;
            }
            
            for(int j=i;j<pos;j++){
                tmp.push_back(v[j].second);
            }
            
            i=pos-1;
            ans.push_back(tmp);
        }
        
        return ans;
    }
};