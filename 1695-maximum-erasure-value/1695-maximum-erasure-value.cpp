class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       
        vector<int> hash_arr(10001, 0);
        
        int start = 0;
        int end = 0;
        
        int res = 0;
        int curr_sum = 0;
        
        while(start<=end && end <nums.size()) {
            
            hash_arr[nums[end]]++;
            curr_sum = curr_sum + nums[end];
            
            while(hash_arr[nums[end]] > 1) {
                
                hash_arr[nums[start]]--;
                curr_sum = curr_sum - nums[start];
                start++;
                
            }
            
            res = max(curr_sum, res);
            
            end++;
        }
        
        return res;
    }
};