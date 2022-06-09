class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res(2,-1);
        
        for(int i=0; i<nums.size(); i++) {
            
            int start = i + 1;
            int end = nums.size() - 1;
            
            
            while((i+1 < nums.size()) && nums[i] == nums[i+1]) {
                if(nums[i] + nums[i+1] != target)
                    i++;
                else {
                    res[0] = i+1;
                    res[1] = i+2;
                    return res;
                }
            }
            
            int temp_target = target - nums[i];
            
            if(temp_target < 0) 
                return res;
            
            while(start <= end) {
                
                int mid  = (start + end)/2;
                
                if(nums[mid] == temp_target) {
                    res[0] = i+1;
                    res[1] = mid+1;
                    return res;
                }
                
                else if (nums[mid] > temp_target) {
                    end = end - 1;
                }
                
                else {
                    start = start + 1;
                }
            }
            
        }
       return res; 
    }
};