class Solution {
public:
    int factorial(int n) {
        int factorial = 1;
        for (int i = 2; i <= n; i++)
            factorial = factorial * i;
        return factorial;
    }
    int nCr(int n, int r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> m;
            int d;
            // cout<<"i: "<<points[i][0]<<" "<<points[i][1]<<endl;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                d=dx*dx;
                d+=(dy*dy);
                m[d]++;
            }
            for(auto x:m){
                // cout<<x.first<<" "<<x.second<<endl;
                if(x.second>=2){
                    int comb=nCr(x.second,2);
                    ans+=(comb*2);
                }
            }
        }    
        return ans;
    }
};