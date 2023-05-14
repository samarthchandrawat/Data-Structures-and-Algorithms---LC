//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int helper(int w, int n, int wt[], int val[], vector<vector<int>> &dp) {
        
        if(w==0 || n==0)
            return 0;
        
        int inc = 0;
        int exc = 0;
        
        if(dp[w][n] != -1) {
            
            return dp[w][n];
        }
        
        if(w-wt[n-1] >= 0) {
            
            inc = val[n-1] + helper(w-wt[n-1], n-1, wt, val, dp);    
        }
        
        exc = helper(w, n-1, wt, val, dp);
        
        return dp[w][n] = max(exc, inc);
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<int> dp(w+1, 0);
        for(int i=1; i<=n; i++) {
            
            for(int j=w; j>=1; j--) {
                
                int inc = 0;
                int exc = 0;
                
                if(j - wt[i-1] >= 0) {
                    
                    inc = dp[j - wt[i-1]] + val[i-1];    
                }
                
                exc = dp[j];
                
                dp[j] = max(inc, exc);
            }
        }
        
        return dp[w];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends