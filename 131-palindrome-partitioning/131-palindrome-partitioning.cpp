class Solution {
public:
    bool isPalindrome(string S){
        for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<string> out,string s,int idx){
           if(idx==s.size()){
                ans.push_back(out);
           }
           string tmp;        
           for(int i=idx;i<s.size();i++){
               tmp+=s[i];
               if(isPalindrome(tmp)){
                    out.push_back(tmp);
                    solve(ans,out,s,i+1);
                    out.pop_back();
               }
               else continue;
           }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> out;
        solve(ans,out,s,0);
        return ans;
    }
};