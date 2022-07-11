class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<int> pq;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
            mp[arr[i]]++;
        }
        
        vector<int> ans;
        ans.push_back(pq.top());
        int c=0;
        for(int i=k;i<n;i++){
            mp[arr[c]]--;
            mp[arr[i]]++;
            pq.push(arr[i]);
            // cout<<"c: "</<c<<" arrc: "<<arr[c]<<" tp: "<<pq.top()<<endl;
            if(pq.top()==arr[c]) pq.pop();
            // cout<<"top: "<<pq.top()<<endl;
            while(mp[pq.top()]==0){
                pq.pop();
            }
            ans.push_back(pq.top());
            c++;
        }
        
        return ans;
    }
};