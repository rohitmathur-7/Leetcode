class Solution {
public:
    int maxArea(vector<int>& height) {
        int a=0,b=height.size()-1,area=INT_MIN;
        while(a<b){
            area=max(area,(b-a)*min(height[a],height[b]));
            if(height[a]<height[b]) a++;
            else b--;
        }
        return area;
    }
};