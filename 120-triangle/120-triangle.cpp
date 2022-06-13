class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int base_len = triangle[triangle.size()-1].size();
        
        vector<vector<int>> dp_arr(base_len, vector<int>(base_len, 10001));
        
        for(int i=0; i<base_len; i++) {
            
            for(int j=0; j<i+1; j++) {
           
                dp_arr[i][j] = triangle[i][j];
            }
            
        }
        
        for(int i = base_len-2; i >= 0; i--) {
            
            for(int j=0; j<=i; j++) {
                
                dp_arr[i][j] = dp_arr[i][j] + min(dp_arr[i+1][j], dp_arr[i+1][j+1]);
            }
        }
        
        return dp_arr[0][0];
    }
};