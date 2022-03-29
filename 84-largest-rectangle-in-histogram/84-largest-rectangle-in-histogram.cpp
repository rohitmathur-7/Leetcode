class Solution {
public:
    int largestRectangleArea(vector<int>& arr){
        int n=arr.size();
        vector<int> ls(n),rs(n);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({arr[i],i});
                ls[i]=0;
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    ls[i]=0;
                }
                else{
                    ls[i]=st.top().second+1;
                }
                st.push({arr[i],i});
            }
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({arr[i],i});
                rs[i]=n-1;
            }
            else{
                while(!st.empty() && st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    rs[i]=n-1;
                }
                else{
                    rs[i]=st.top().second-1;
                }
                st.push({arr[i],i});
            }
        }
        int mx=INT_MIN,area;
        for(int i=0;i<n;i++){
            area=(rs[i]-ls[i]+1)*arr[i];
            mx=max(area,mx);
        }
        return mx;
    }
};