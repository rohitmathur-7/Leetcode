class Solution {
public:
    string minRemoveToMakeValid(string s){
        stack<int> st;
        int n=s.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    v.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        if(v.size()){
            sort(v.begin(),v.end(),greater<int>());
            int j=0;
            for(int i=n-1;i>=0;i--){
                if(i==v[j]){
                    s.erase(s.begin()+i);
                    j++;
                    if(j==v.size()){
                        break;
                    }
                }
            }
        }
        
        return s;
    }
};