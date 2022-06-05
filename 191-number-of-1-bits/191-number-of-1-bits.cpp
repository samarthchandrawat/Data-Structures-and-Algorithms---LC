class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n>0){
            int last_bit = n&1;
            res = res + last_bit;   
            n=n>>1;
        }
        return res;
    }
};