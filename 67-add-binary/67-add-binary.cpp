class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int x=a.size()-1,y=b.size()-1;
        bool carry=false;
        while(x>=0 && y>=0){
            if(a[x]=='1' && b[y]=='1'){
                if(carry){
                    ans+='1';
                }
                else ans+='0';
                carry=true;
            }
            else if((a[x]=='1' && b[y]=='0') || (a[x]=='0' && b[y]=='1')){
                if(carry) ans+='0';
                else ans+='1';
            }
            else if(a[x]=='0' && b[y]=='0'){
                if(carry){
                    ans+='1';
                    carry=false;
                }
                else ans+='0';
            }
            x--,y--;
        }
        while(x>=0){
            if(a[x]=='1'){
                if(carry) ans+='0';
                else ans+='1';
            }
            else{
                if(carry){
                    ans+='1';
                    carry=false;
                }
                else ans+='0';
            }
            x--;
        }
        while(y>=0){
            if(b[y]=='1'){
                if(carry) ans+='0';
                else ans+='1';
            }
            else{
                if(carry){
                    ans+='1';
                    carry=false;
                }
                else ans+='0';
            }
            y--;
        }
        if(carry) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};