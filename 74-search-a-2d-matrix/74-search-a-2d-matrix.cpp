class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start_col = 0, end_col = n-1, start_row=0, end_row=m-1;
        
        int curr_x = start_row;
        int curr_y = end_col;
        
        while(curr_x <= end_row && curr_y >= start_col) {
            if(matrix[curr_x][curr_y] == target) {
                return true;
            } else if(matrix[curr_x][curr_y] < target) {
                curr_x++;
            } else {
                curr_y--;
            }
        }
        return false;
    }
};