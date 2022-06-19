class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> curr_row(n, 1);
        
        for(int i=1; i<m; i++) {
            
            for(int j=1; j<n; j++) {
                
                curr_row[j] = curr_row[j] + curr_row[j-1];
            }
        }
        
        return curr_row[n-1];
    }
};