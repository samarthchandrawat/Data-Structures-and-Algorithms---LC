class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end) {
            
            int mid = (start + end)/2;
            
            if( (mid+1 <= nums.size()-1) && (mid - 1>=0) &&
                nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                return mid;
            } 
            else if((mid+1 <= nums.size()-1) && nums[mid+1] > nums[mid]) {
                start = mid+1;
            }
            else if((mid - 1>=0) && nums[mid-1] > nums[mid]) {
                end = mid -1;
            } 
            else if(mid ==0) {
                return 0;
            } 
            else if(mid == nums.size()-1) {
                return nums.size()-1;
            }
        }
        
        return start;
        
    }
};