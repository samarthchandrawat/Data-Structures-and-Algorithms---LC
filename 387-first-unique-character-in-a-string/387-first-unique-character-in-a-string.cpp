class Solution {
public:
    
    int firstUniqChar(string s) {
        
        int chars_hash[26] = {0};
        
        int res = -1;
        
        for(int i=0; i<s.length(); i++) {
            
            chars_hash[s[i]-'a']++;
        }
        
        for(int i=0; i<s.length(); i++) {
            
            if(chars_hash[s[i]-'a'] == 1) {
                
                return i;
            }
        }
        
        return -1;
    }
};