class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start_row = 0;
        int start_col = 0;
        int end_row = m-1;
        int end_col = n-1;
        
        vector<int> res;
        while(start_row<=end_row and start_col<=end_col) {
            
            for(int i=start_col; i<=end_col; i++) {
                res.push_back(matrix[start_row][i]);
            }
            
            for(int i=start_row+1; i<=end_row; i++) {
                res.push_back(matrix[i][end_col]);
            }
            
            for(int i=end_col-1; i>=start_col; i--) {
                if(start_row != end_row)
                    res.push_back(matrix[end_row][i]);
            }
            
            for(int i=end_row-1; i>start_row; i--) {
                if(start_col != end_col)
                    res.push_back(matrix[i][start_col]);
            }
            
            start_row++;
            start_col++;
            end_row--;
            end_col--;
        }
        
        return res;
    }
};