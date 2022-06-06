class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //using kadane algorith for lasrgest sub array sum
        
        int curr_sum = 0;
        int max_sum = 0;
        int le = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            
            le = max(le, nums[i]);
            
            curr_sum += nums[i];
            
            if(curr_sum < 0)
                curr_sum = 0;

            max_sum = max(curr_sum, max_sum);
        }
        
        if(le < 0)
            return le;
        
        return max_sum;
    }
};