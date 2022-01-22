// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void util(stack<int>&s,int mid,int pos){
        if(mid==pos){
            s.pop();
            return;
        }
        int a=s.top();
        s.pop();
        util(s,mid,pos-1);
        s.push(a);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int mid=ceil((float)sizeOfStack/2);
        int pos=sizeOfStack;
        util(s,mid,pos);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends