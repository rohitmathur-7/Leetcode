class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        int n=arr.size();
        int z=0,ans=INT_MIN,l;
        bool o=false;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(z==0) l=i;
                z++;
                if(i==n-1){
                    ans=max(ans,z);
                }
            }
            else{
                if(!o){
                    if(z>0) ans=max(ans,z);
                }
                else{
                    if(z>0){
                        int d=ceil((float)(i-l)/2);
                        // cout<<"d: "<<d<<endl;
                        ans=max(ans,d);
                    }
                }
                z=0;
                o=true;
            }
        }
        return ans;
    }
};