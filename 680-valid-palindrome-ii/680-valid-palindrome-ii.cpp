class Solution {
public:
    bool validPalindrome(string s){
        string tmp;
        tmp=s;
        reverse(tmp.begin(),tmp.end());
        if(tmp==s) return true;
        int a=0,b=s.size()-1;
        while(a<b){
            if(s[a]!=s[b]){
                string tmp1=s;
                tmp1.erase(tmp1.begin()+a);
                string tmp2;
                tmp2=tmp1;
                reverse(tmp2.begin(),tmp2.end());
                if(tmp2==tmp1) return true;
                tmp1=s;
                tmp1.erase(tmp1.begin()+b);
                tmp2;
                tmp2=tmp1;
                reverse(tmp2.begin(),tmp2.end());
                if(tmp2==tmp1) return true;
                break;
            }
            a++,b--;
        }
        return false;
    }
};