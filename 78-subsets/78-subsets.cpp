class Solution {
public:
    
    void subsets_rec(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        
        if(i >= nums.size()) {
            
            res.push_back(curr);
            return;
        }
        
        // include ith number
        
        curr.push_back(nums[i]);
        subsets_rec(nums, res, curr, i+1);
        
        //exclude ith number
        
        curr.pop_back();
        subsets_rec(nums, res, curr, i+1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // using backtracking
        
        vector<vector<int>> res;
        vector<int> curr;
        
        subsets_rec(nums, res, curr, 0);
        
        return res;
    }
};