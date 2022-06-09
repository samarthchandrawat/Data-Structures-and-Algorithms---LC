class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0; i<nums.size()-1; i++) {
            
            int start = i + 1;
            int end = nums.size() - 1;
            
            while(nums[i] == nums[i+1]) {
                if(nums[i] + nums[i+1] == target)
                        return {i+1, i+2};
                else 
                    i++;
            }
            
            while(start <= end) {
                
                int mid  = (start + end)/2;
                
                if(nums[mid] == target - nums[i]) {
                    return {i + 1, mid + 1};
                }
                
                else if (nums[mid] > target - nums[i]) {
                    end = end - 1;
                }
                
                else {
                    start = mid + 1;
                }
            }
            
        }
       return {-1, -1}; 
    }
};