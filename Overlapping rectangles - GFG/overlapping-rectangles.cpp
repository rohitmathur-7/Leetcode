// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        int otr[2]={R1[0],L1[1]};
        int obl[2]={L1[0],R1[1]};
        int ttr[2]={R2[0],L2[1]};
        int tbl[2]={L2[0],R2[1]};
        
        //for points
        if(L1[0]>=L2[0] && L1[0]<=R2[0] && L1[1]>=R2[1] && L1[1]<=L2[1]) return 1;
        if(R1[0]>=L2[0] && R1[0]<=R2[0] && R1[1]>=R2[1] && R1[1]<=L2[1]) return 1;
        if(otr[0]>=L2[0] && otr[0]<=R2[0] && otr[1]>=R2[1] && otr[1]<=L2[1]) return 1;
        if(obl[0]>=L2[0] && obl[0]<=R2[0] && obl[1]>=R2[1] && obl[1]<=L2[1]) return 1;
        
        if(L2[0]>=L1[0] && L2[0]<=R1[0] && L2[1]>=R1[1] && L2[1]<=L1[1]) return 1;
        if(R2[0]>=L1[0] && R2[0]<=R1[0] && R2[1]>=R1[1] && R2[1]<=L1[1]) return 1;
        if(ttr[0]>=L1[0] && ttr[0]<=R1[0] && ttr[1]>=R1[1] && ttr[1]<=L1[1]) return 1;
        if(tbl[0]>=L1[0] && tbl[0]<=R1[0] && tbl[1]>=R1[1] && tbl[1]<=L1[1]) return 1;
        
        //for sides
        if(L1[1]<=L2[1] && obl[1]>=tbl[1] && L1[0]<=L2[0] && R1[0]>=R2[0]) return 1;
        if(L2[1]<=L1[1] && tbl[1]>=obl[1] && L2[0]<=L1[0] && R2[0]>=R1[0]) return 1;
        
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends