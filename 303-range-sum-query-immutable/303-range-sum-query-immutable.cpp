class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
        }
        prefix = nums;
    }
    
    int sumRange(int left, int right) {
        return (left == 0) ? prefix[right] : prefix[right]-prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */