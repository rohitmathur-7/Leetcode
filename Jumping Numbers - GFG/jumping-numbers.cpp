//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long x) {
        // code here
        queue<long long> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(7);
        q.push(8);
        q.push(9);
        int a,num1,num2,r;
        while(!q.empty()){
            a=q.front();
            q.pop();
            r=a%10;
            if(r==0){
                num1=(a*10)+r+1;
                if(num1<=x) q.push(num1);
                else break;
            }
            else if(r==9){
                num1=(a*10)+r-1;
                if(num1<=x) q.push(num1);
                else break;
            }
            else{
                num1=(a*10)+r-1;
                num2=(a*10)+r+1;
                if(num1<=x) q.push(num1);
                if(num2<=x) q.push(num2);
                if(num1>x || num2>x) break;
            }
        }
        while(q.size()>1) q.pop();
        
        return q.front();
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends