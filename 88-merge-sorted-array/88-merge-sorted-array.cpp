class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0,shift=0,tmp=0;
        for(int i=0;i<m+shift;i++){
            if(a<nums2.size() && nums2[a]<=nums1[i]){
                // cout<<"i: "<<i<<" arr: "<<nums1[i]<<endl;
                for(int j=m+shift-1;j>=i;j--){
                    if(j+1<n+m) nums1[j+1]=nums1[j];
                }
                nums1[i]=nums2[a];
                shift++;
                tmp++;
                a++;
            }
        }
        if(tmp<n){
            for(int i=m+shift;i<n+m;i++){
                nums1[i]=nums2[tmp];
                tmp++;
            }
        }
    }
};