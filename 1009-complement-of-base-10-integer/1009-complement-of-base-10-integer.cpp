class Solution {
public:
    int bitwiseComplement(int n) {
        
        int complement = 0;
        long int a = 1;
        
        if(n == 0)
            return 1;
        
        while(n > 0) {
            
            int last_bit = n & 1;
            if(!last_bit) {
                complement += a;
            }
            a = a*2;
            n = n>>1;
        }
        
        return complement; 
    }
};