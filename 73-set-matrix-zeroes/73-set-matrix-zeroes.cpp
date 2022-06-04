class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> col_zero(n,0);
        vector<int> row_zero(m,0);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n ;j++) {
                if(matrix[i][j] == 0) {
                    col_zero[j] = 1;
                    row_zero[i] = 1;
                }
            }
        }
        
        for(int i=0; i<m ; i++) {
            for(int j=0; j<n; j++) {
                if(col_zero[j]==1 || row_zero[i]==1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};