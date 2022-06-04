class Solution {
public:
    vector<int> computeHash(string s) {
        vector<int> hash_vector(26,0);
        for(char x: s) {
            hash_vector[x - 97]++;
        }
        return hash_vector;
    }
    
    bool hashEqual(vector<int> a, vector<int> b) {
        for(int i=0;i<a.size();i++) {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> hash_s1 = computeHash(s1);

        int i =0;
        int j =s1.length();
        while(i+j <= s2.length()) {
            string temp = s2.substr(i, j);
            if(hashEqual(hash_s1, computeHash(temp))) {
                return true;
            }
            i++;   
       }
       return false;
   }
};