class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(ops[i]!="C" && ops[i]!="D" && ops[i]!="+"){
                stringstream geek(ops[i]);
                int x=0;
                geek>>x;
                arr.push_back(x);
            }
            else{
                int sze=arr.size();
                if(ops[i]=="C"){
                    arr.erase(arr.begin()+sze-1);
                }
                else if(ops[i]=="D"){
                    arr.push_back(arr[sze-1]*2);
                }
                else{
                    arr.push_back(arr[sze-1]+arr[sze-2]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<arr.size();i++) ans+=arr[i];
        return ans;
    }
};