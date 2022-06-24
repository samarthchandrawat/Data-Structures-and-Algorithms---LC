class Solution {
public:
    bool isPalindrome(string str) {
        string alNumString = "";
        for(char x : str) {
            if((x>='0' && x<='9') || (x >='a' && x<='z') || (x >='A' && x<='Z')) {
                alNumString += tolower(x);
            }
        }
        
        int l = 0;
        int h = alNumString.length() - 1;
        while((l <= h) && (alNumString[l] == alNumString[h]) && (l <= h)) {
            l++;
            h--;
        }
        
        if(l > h) {
            return true;    
        }
        return false;
    }
};