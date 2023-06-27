//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool _union(int a, int b, vector<int> &par, vector<int> &rank) {
        
        int pa = _find(a, par);
        int pb = _find(b, par);
        
        if(pa == pb)
            return false;
        
        if(rank[pa]>rank[pb]) {
            
            par[pb] = pa;
            rank[pa]++;
        } else {
            
            par[pa] = pb;
            rank[pb]++;
        }
        
        return true;
        
    }
    
    int _find(int a, vector<int> &par) {
        
        int pa = par[a];
        while(pa != par[pa]) {
            
            par[pa] = par[par[pa]];
            pa = par[pa];
        }
        
        return pa;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // using union find
        
        int comp = V;
        vector<int> par(V, -1);
        vector<int> rank(V, 1);
        
        for(int i=0; i<V; i++)
            par[i] = i;
        
        for(int i=0; i<V; i++) {
            
            for(int j=0; j<V; j++) {
                
                if(i<j && adj[i][j]==1) {
                    
                    if(_union(i, j, par, rank)) {
                        
                        comp--;
                    }
                }
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