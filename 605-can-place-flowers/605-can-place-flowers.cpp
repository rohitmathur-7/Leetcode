class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int k){
        int n=f.size();
        int z=0,pos,oz;
        for(int i=0;i<n;i++){
            if(f[i]==1){
                pos=i;
                break;
            }
            else z++;
        }
        oz=z;
        int ans=0,d=0;
        if(z>0) d=ceil(z/2);
        ans+=d;
        z=0;
        bool one=false;
        for(int i=pos;i<n;i++){
            if(f[i]==0){
                z++;
                if(i==n-1){
                    d=z/2;
                    ans+=d;
                }
            }
            else{
                one=true;
                if(z>0){
                    d=ceil((float)z/2)-1;
                    ans+=d;
                    // cout<<"z: "<<z<<" d: "<<d<<endl;
                }
                z=0;
            }
            if(ans>=k) return true;
        }
        if(!one){
            if(ceil((float)oz/2)>=k) return true;
        }
        return false;
    }
};