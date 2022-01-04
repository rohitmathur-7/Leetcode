class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int num=0,c=0;
        while(n){
            if(!(n&1)){
                num+=(pow(2,c));
            }
            n>>=1;
            c++;
        }
        return num;
    }
};