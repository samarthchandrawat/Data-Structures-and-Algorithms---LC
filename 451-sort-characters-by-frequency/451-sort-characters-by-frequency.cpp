class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> char_freq;
        
        for(char c: s) {
                
            char_freq[c]++;
        }
        
        vector<vector<char>> freq_char(s.length()+1);
        
        for(auto x: char_freq) {
            
            freq_char[x.second].push_back(x.first);
        }
        
        string res ="";
        
        for(int i=s.length(); i>0; i--) {
            
            for(auto x: freq_char[i]) {
                
                res = res + string(i, x);
            }
        }
        
        return res;
    }
};