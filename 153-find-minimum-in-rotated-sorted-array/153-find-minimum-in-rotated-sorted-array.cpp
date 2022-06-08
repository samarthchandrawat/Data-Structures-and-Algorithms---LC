class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            
            int mid = (start + end) /2;
            
            if(nums[start] < nums[end]) {
                return nums[start];
            }
            
            if(nums[mid] > nums[mid+1]) {
                return nums[mid + 1];
            }
            
            if(nums[mid-1] >nums[mid]) {
                return nums[mid];
            }
            
            if(nums[mid] > nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return nums[start];
    }
};