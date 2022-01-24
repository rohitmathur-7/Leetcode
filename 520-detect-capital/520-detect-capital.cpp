class Solution {
public:
    bool detectCapitalUse(string s) {
        //65-90
        //97-122
        bool fc=false;
        int c=0,l=0;
        for(int i=0;i<s.size();i++){
            if(s[0]>=65 && s[0]<=90) fc=true;
            if(s[i]>=65 && s[i]<=90){
                c++;
            }
            if(s[i]>=97 && s[i]<=122){
                l++;
            }
        }
        // cout<<l<<" "<<c<<endl;
        if(l==s.size() || c==s.size()) return true;
        if(l==s.size()-1 && fc) return true;
        return false;
    }
};