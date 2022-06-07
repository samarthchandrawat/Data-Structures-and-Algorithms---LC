class Solution {
public:
    
    int helper(vector<int> &nums, int target, int start, int end) {
        
        if(start > end) {
            return -1;
        }
        
        int mid = (start + end)/2;
        
        if(nums[mid] == target) {
            return mid;
        }
        
        //mid is before pivot
        if(nums[start] <= nums[mid]) {
            
            if(target >= nums[start] && target <= nums[mid]) {
                
                return helper(nums, target, start, mid);

            } else {
                return helper(nums, target, mid + 1, end);
            }
        } 
        
        else if (nums[mid] <= nums[end]) {
            
            if(target >= nums[mid] && target <= nums[end]) {
                
                return helper(nums, target, mid, end);
            
            } else {
                return helper(nums, target, start, mid-1);
            }
        }
        
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        return helper(nums, target, start, end);
    }
};