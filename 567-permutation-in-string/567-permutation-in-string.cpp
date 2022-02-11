class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        unordered_map<int,int> m1,m2;
        for(int i=0;i<n1;i++){
            m1[s1[i]]++;
        }
        for(int i=0;i<n2;i++){
            m2[s2[i]]++;
            if(i>=(n1-1)){
                int d=(i+1)-1-n1;
                // cout<<"d: "<<d<<endl;
                if(d>=0) m2[s2[d]]--;
                bool g=true;
                for(auto x:m1){
                    if(m2[x.first]!=x.second){
                        g=false;
                        break;
                    }
                }
                if(g) return true;
            }
        }
        return false;
    }
};