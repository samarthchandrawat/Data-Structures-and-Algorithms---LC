class Solution {
public:
    
    bool isPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        if(s == r) {
            return true;
        }
        
        return false;
    }
    
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) {
            return 1;
        } else {
            return 2;
        }
    }
};