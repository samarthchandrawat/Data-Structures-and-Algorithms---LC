class Solution {
public:
    string longestPalindrome(string s) {
    
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int res_x = 0;
        int res_y = 0;
        
        int res_len = 1;
        
        for(int i=0; i<n; i++) {
                
            dp[i][i] = 1;
            
            if( i+1<n && s[i] == s[i+1] ) {
                
                dp[i][i+1] = 1;
                
                res_x = i;
                res_y = i+1;
                
                res_len = 2;
                
            } else if(i+1 < n){
                
                dp[i][i+1] = 0;
            }
        }
        
        for(int size=3; size<=n; size++) {

            int i=0;
            
            while(i+size <=n) {
                
                if(s[i] == s[i + size - 1]) {
                
                    dp[i][i+size-1] = dp[i+1][i+size-2];
                } else {

                    dp[i][i+size-1] = 0;
                }

                if(dp[i][i+size-1]==1 && size>res_len) {

                    res_x = i;
                    res_y = i+size-1;

                    res_len = size;
                }

                i++;
            }
            
        }
        
        return s.substr(res_x, res_y - res_x + 1);
        
    }
};