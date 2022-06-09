class Solution {
public:
    
    void per_rec(vector<vector<int>> &res, vector<int>& nums, int i) {
        
        if( i >= nums.size() ) {
            
            res.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++) {
            
            swap(nums[i], nums[j]);
            per_rec(res, nums, i+1);
            swap(nums[j], nums[i]);

        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        per_rec(res, nums, 0);
        
        return res;
    }
};