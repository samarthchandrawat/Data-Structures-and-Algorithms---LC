class Solution {
public:
    
    static bool len_comp(string s1, string s2) {
        
        return (s1.length() < s2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string, int> mx_chain;
        
        int res = 0;
        
        for(string s: words) {
            
            mx_chain[s]++;
        }
        
        sort(words.begin(), words.end(), len_comp);
        
        for(int i=0; i<words.size(); i++) {
            
            int mx_yet = 0;
            
            for(int j=0; words[i].size()>1 && j<words[i].size(); j++) {
                
                mx_yet = max(mx_yet, mx_chain[ words[i].substr(0,j) + words[i].substr(j+1, (words[i].length() - j -1)) ]);
            }
            
            mx_chain[words[i]] = 1 + mx_yet;
            
            res = max(res, mx_chain[words[i]]);
        }
        
        return res;
    }
};