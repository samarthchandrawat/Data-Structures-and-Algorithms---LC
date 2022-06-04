class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int count = 1;
        for(int i=0; i<chars.size(); i++) {
            while(i+1<chars.size() && chars[i]==chars[i+1]) {
                i++;
                count++;
            }
            s += chars[i];
            if(count > 1)
                s += to_string(count);
            count = 1;
        }
        chars.clear();
        for(char c: s) {
            chars.push_back(c);
        }
        return chars.size();
    }
};