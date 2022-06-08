class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2, -1);
        
        int start = 0;
        int end  = nums.size() - 1;
        
        //search leftmost 
        
        while(start <= end) {
            
            int mid = (start + end)/2;
            
            if(nums[mid] == target && (mid == 0 || nums[mid-1] != target)) {
                res[0] = mid;
                break;
            }
            
            if(nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        if(res[0] == -1) {
            return res;
        }
        
        start = 0;
        end  = nums.size() - 1;
        
        //search leftmost 
        
        while(start <= end) {
            
            int mid = (start + end)/2;
            
            if(nums[mid] == target && (mid == nums.size()-1 || nums[mid+1] != target)) {
                res[1] = mid;
                break;
            }
            
            if(nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return res;
        
        
    }
};