class Solution {
public:
    void solve(string s,string out,vector<string>& ans){
        if(s.size()==0){
            ans.push_back(out);
            return;
        }
        string s1=out;
        string s2=out;
        if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
            s1.push_back(tolower(s[0]));
            s2.push_back(toupper(s[0]));
            s.erase(s.begin()+0);
            solve(s,s1,ans);
            solve(s,s2,ans);
        }
        else{
            s1.push_back(s[0]);
            s.erase(s.begin()+0);
            solve(s,s1,ans);
        }
    
        return;        
    }
    vector<string> letterCasePermutation(string s) {
        string out="";
        vector<string> ans;
        solve(s,out,ans);
        return ans;
    }
};