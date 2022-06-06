class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        vector<int> digits;
        
        while(x>0) {
            
            digits.push_back(x%10);
            x = x/10;
        }
        
        for(int i=0; i<digits.size(); i++) {
            
            if(digits[i] != digits[digits.size()-1-i])
                return false;
        }
        
        return true;
    }
};