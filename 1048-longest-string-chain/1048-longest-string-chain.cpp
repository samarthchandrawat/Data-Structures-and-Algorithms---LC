class Solution {
public:
    
    static bool len_comp(string s1, string s2) {
        
        return (s1.length() < s2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string, int> dp;
        
        int res = 0;
        
        sort(words.begin(), words.end(), len_comp);
        
        for(int i=0; i<words.size(); i++) {
            
            int max_reducing_one_char = 0;
            
            for(int j=0; j<words[i].size(); j++) {
                
                max_reducing_one_char =  dp[ words[i].substr(0,j) + words[i].substr(j+1) ];
            
                dp[words[i]] = max(dp[words[i]], 1 + max_reducing_one_char);
            
                res = max(res, dp[words[i]]);
            }
        }
        
        return res;
    }
};