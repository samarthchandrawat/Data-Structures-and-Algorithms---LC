//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int i, int V, vector<int> &visited, vector<vector<int>> &L) {
        
        if(i>=V)
            return;
            
        if(visited[i])
            return;
            
        visited[i] = true;
        
        for(int nbr: L[i]) 
            dfs(nbr, V, visited, L);
        
        return;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> L(V);
        for(int i=0; i<V; i++) {
            
            for(int j=0; j<V; j++) {
                
                if(adj[i][j]==1 && i!=j) {
                    
                    L[i].push_back(j);
                }
            }
        }
        
        int comp = 0;
        vector<int> visited(V, false);
        
        for(int i=0; i<V; i++) {
                
            //dfs
            if(!visited[i]) {
                
                comp++;
                dfs(i, V, visited, L);
            }
        }
            
        return comp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends