class Solution {
public:
    int strStr(string haystack, string needle){
        int a;
        for(int i=0;i<haystack.size();i++){
            int j=i;a=0;
            while(haystack[j]==needle[a]){
                j++;a++;
                if(a==needle.size()) return i;
            }
        }
        return -1;
    }
};