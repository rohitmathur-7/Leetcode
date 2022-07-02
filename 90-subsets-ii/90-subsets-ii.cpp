class Solution {
public:
    void sub(vector<int> tmp,int idx,int n,set<vector<int> >& st,vector<int> arr){
        if(idx==n) return;
        for(int j=idx;j<n;j++){
            tmp.push_back(arr[j]);
            st.insert(tmp);
            sub(tmp,j+1,n,st,arr);
            tmp.erase(tmp.begin()+tmp.size()-1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<vector<int> > st;
        int n=arr.size();
        vector<int> empty;
        st.insert(empty);
        for(int i=0;i<n;i++){
            vector<int> tmp;
            tmp.push_back(arr[i]);
            st.insert(tmp);
            sub(tmp,i+1,n,st,arr);
        }
        vector<vector<int> > ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};