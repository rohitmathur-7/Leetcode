class Solution {
public:
    bool is_palindrome(string tmp){
        string tmp1=tmp;
        reverse(tmp1.begin(),tmp1.end());
        if(tmp==tmp1) return 1;
        return 0;
    }
    
    void solve(int idx,vector<string> ds,string tmp,vector<vector<string> > &ans,string s){
        if(idx==s.size()){
            if(is_palindrome(tmp)){
                ans.push_back(ds);
            }
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            tmp+=s[i];
            if(is_palindrome(tmp)){
                ds.push_back(tmp);
                solve(i+1,ds,"",ans,s);
                ds.pop_back();
            }
        }
    
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        string tmp;
        vector<string> ds;
        
        solve(0,ds,tmp,ans,s);
        
        return ans;
    }
};