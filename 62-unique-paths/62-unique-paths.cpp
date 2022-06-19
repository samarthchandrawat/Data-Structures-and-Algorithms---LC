class Solution {
public:
    
    int rec(int m, int n, int i, int j, vector<vector<int>> &ways) {
        
        if(i>=m && j>=n) {
            
            return 0;
        }
        
        if(i==m-1 && j==n-1) {
            
            return 1;
        }
        
        
        if(ways[i][j+1] == -1) {
            
            ways[i][j+1] = rec(m, n, i, j+1, ways);
        }
        
        if(ways[i+1][j] == -1) {
            
            ways[i+1][j] = rec(m, n, i+1, j, ways);
        }
        
        ways[i][j] = ways[i+1][j] + ways[i][j+1];
        
        return ways[i][j];
        
    } 
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> ways(m+1, vector<int>(n+1, -1));
        
        for(int i=0; i<=n; i++) {
            ways[m][i] = 0;
        }
        
        for(int i=0; i<=m; i++) {
            ways[i][n] = 0;
        }
        
        rec(m, n, 0, 0, ways);
        
        
        return (ways[0][0] == -1 ? 1 : ways[0][0]);
    }
};