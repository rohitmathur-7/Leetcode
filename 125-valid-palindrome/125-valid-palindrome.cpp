class Solution {
public:
    bool isPalindrome(string s) {
        int a=0;
        int b=s.size();
        while(a<b){
            if(s[a]>='a' && s[a]<='z' || s[a]>='A' && s[a]<='Z' || s[a]>='0' && s[a]<='9'){
                if(s[b]>='a' && s[b]<='z' || s[b]>='A' && s[b]<='Z' || s[b]>='0' && s[b]<='9'){
                    if(tolower(s[a])!=tolower(s[b])) return false;
                    a++,b--;
                }
                else b--;
            }
            else a++;
        }
        
        return true;
    }
};