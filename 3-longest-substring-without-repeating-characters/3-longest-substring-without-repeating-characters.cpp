class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0;
        int j = 0;
        
        int res = 0;
        int hash_arr[1000] = {0};
        
        while( i<=j && j<s.length() ) {
            
            hash_arr[ (int)s[j] ]++;
            
            while(hash_arr[ (int)s[j] ] >= 2) {
                hash_arr[ (int)s[i] ]--;
                i++;    
            }
            
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
        
    }
};