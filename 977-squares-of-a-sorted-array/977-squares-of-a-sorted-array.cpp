class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a=0,b=nums.size()-1;
        
        while(a<b){
            // cout<<"nums[a]: "<<nums[a]<<" nums[b]: "<<nums[b]<<endl;
            if(abs(nums[b])>abs(nums[a])){
                b--;
            }
            else if(abs(nums[b])==abs(nums[a])){
                nums.erase(nums.begin()+a);
                nums.insert(nums.begin()+b,nums[b-1]);
                b--;
            }
            else{
                int d=nums[a];
                nums.erase(nums.begin()+a);
                nums.insert(nums.begin()+b,d);
                b--;
            }
            // for(int i=0;i<nums.size();i++){
            //     cout<<nums[i]<<" ";
            // }   
            // cout<<endl;
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }   
        
        return nums;
    }
};