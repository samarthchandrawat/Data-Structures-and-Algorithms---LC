class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        
        while( start <= end ) {
            
            int mid = (start + end)/2;
            
            if(nums[mid] == target) {
                return mid;
            }
            
            //mid lies before pivot
            if(nums[start] <= nums[mid]) {
                
                if(target >= nums[start] && target <= nums[mid]) {
                    
                    end = mid;
                } else {
                   
                    start = mid + 1;
                }
            } else {
                //mid lies after pivot
                if(target >= nums[mid] && target <= nums[end]) {
                    
                    start = mid;
                } else {
                   
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};