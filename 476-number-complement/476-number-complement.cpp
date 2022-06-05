class Solution {
public:
    int findComplement(int num) {
        
        int complement = 0;
        long int a = 1;
        while(num > 0) {
            
            int last_bit = (num & 1);
            if(!last_bit) {
                complement += a;
            }
            a = a*2;
            num = num>>1;
        }
        return complement; 
    }
};