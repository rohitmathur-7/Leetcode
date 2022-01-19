// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
   public:
   static bool cmp(pair<double,pair<int,int> > a,pair<double,pair<int,int> > b){
       return a.first>b.first; 
   }
   double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        pair<double,pair<int,int> > p[n];
        for(int i=0;i<n;i++){
            double d=(double)((double)arr[i].value/(double)arr[i].weight);
            p[i].first=d;
            p[i].second.first=arr[i].weight;
            p[i].second.second=arr[i].value;
        }
        sort(p,p+n,cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(p[i].second.first<=W){
                ans+=p[i].second.second;
                W-=p[i].second.first;
            }
            else{
                double qq=(double)((double)(p[i].second.second*W)/p[i].second.first);
                ans+=qq;
                break;
            }
        }
        return ans;
    }
       
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends