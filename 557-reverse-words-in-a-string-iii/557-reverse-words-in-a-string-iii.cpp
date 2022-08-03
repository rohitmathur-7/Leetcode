class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        int a=0,b;
        for(int i=0;i<n;i++){
            if(s[i]==' ' || i==n-1){
                if(i!=n-1) b=i-1;
                else b=i;
                while(a<b){
                    swap(s[a],s[b]);
                    a++,b--;
                }
                a=i+1;
            }
        }
        return s;
    }
};