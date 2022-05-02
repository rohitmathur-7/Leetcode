class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int n=arr.size(),pos=0;
        for(int i=0;i<n;i++){
            if(!(arr[i]&1)){
                for(int j=0;j<i;j++){
                    if(arr[j]&1){
                        swap(arr[i],arr[j]);
                        break;
                    }
                }
            }
        }
        return arr;
    }
};