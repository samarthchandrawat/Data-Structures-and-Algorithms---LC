class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = 0;
        
        for( int num: nums ) {
            total += num;    
        }
        
        if(x > total)
            return -1;
        
        int sub_array_sum = total - x;
        
        int start = 0;
        int end = 0;
        int curr_sum=0;
        int res = -1;
        
        while(start<=end && end<nums.size()) {
            
            curr_sum += nums[end];
            
            while(curr_sum > sub_array_sum) {
                
                curr_sum = curr_sum - nums[start];                
                start++;
            }
            
            if(curr_sum == sub_array_sum)
                res = max(res, end-start+1);
            
            end++;
            
        }
        
        if(res >= 0)
            return nums.size() - res;
        
        return -1;
    }
};