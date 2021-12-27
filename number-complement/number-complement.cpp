class Solution {
public:
    int findComplement(int num) {
         int n=0,c=0;
         while(num){
            if(!(num&1)){
                n+=pow(2,c);
            }
             c++;
             num>>=1;
         }
        return n;
    }
};