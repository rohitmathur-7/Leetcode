class Solution {
public:
    
    bool can(int mid,vector<int> arr){
        for(int i=0;i<mid;i++){
            if(arr[i]>=arr[mid]) return false;
        }
        for(int i=arr.size()-1;i>mid;i--){
            if(arr[i]>=arr[mid]) return false;
        }
        
        return true;
    }
    
    int peakIndexInMountainArray(vector<int>& arr){
        int n=arr.size();
        int l=0,r=n-1,mid,ans=-1;
        while(r>(l+1)){
            mid=l+(r-l)/2;
            if(can(mid,arr)){
                ans=mid;
                break;
            }
            else{
                if(arr[mid-1]<arr[mid]){
                    l=mid;
                }
                else{
                    r=mid;
                }
            }
        }
        
        return ans;
    }
};