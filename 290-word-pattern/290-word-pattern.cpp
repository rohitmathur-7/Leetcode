class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        int n=s.size();
        int a=0,i=0;
        string word;
        for(i=0;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
                if(i==n-1){
                    if(m1.count(pattern[a]) && m1[pattern[a]]!=word) return false;
                    if(m2.count(word) && m2[word]!=pattern[a]) return false;
                    a++;
                }
            }else{
                if(m1.count(pattern[a]) && m1[pattern[a]]!=word) return false;
                else if(!m1.count(pattern[a])) m1[pattern[a]]=word;
                if(m2.count(word) && m2[word]!=pattern[a]) return false;
                else if(!m2.count(word)) m2[word]=pattern[a];
                a++;
                word="";
            }
        }
        if(i==n && a<pattern.size()) return false;
        return true;
    }
};