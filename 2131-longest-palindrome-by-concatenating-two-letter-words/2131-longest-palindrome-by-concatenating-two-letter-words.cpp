class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        map<string,int> mp;
        for(auto x:words) mp[x]++;
        bool g=true;
        // for(auto x:mp) cout<<x.first<<endl;
        for(auto x:mp){
            string tmp;
            tmp+=x.first[1];
            tmp+=x.first[0];
            if(mp.count(tmp)){
                if(tmp!=x.first){
                    ans+=(4*min(x.second,mp[tmp]));
                    // mp.erase(x.first);
                    mp.erase(tmp);
                    // mp[x.first]=0;
                    // mp[tmp]=0;
                }
                else{
                    if(x.second>1){
                        if(x.second&1){
                            if(g){
                                ans+=(2*x.second);
                                g=false;
                            }
                            else{
                                ans+=(2*(x.second-1));
                            }
                        }
                        else{
                            ans+=(2*x.second);
                        }
                    }
                    else{
                        if(g){
                            ans+=2;
                            g=false;    
                        }
                    }
                    // mp.erase(tmp);
                    // mp[x.first]=0;
                }
            }
        }
        
        return ans;
    }
};