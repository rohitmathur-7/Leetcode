class Solution {
public:
    bool isHappy(int n){
        set<int> st;
        st.insert(n);
        while(true){
            int sum=0;
            while(n){
                int r=n%10;
                sum+=(r*r);
                n/=10;
            }
            if(sum==1) return true;
            if(st.find(sum)!=st.end()) return false;
            n=sum;
            st.insert(n);
        }
        
        return true;
    }
};