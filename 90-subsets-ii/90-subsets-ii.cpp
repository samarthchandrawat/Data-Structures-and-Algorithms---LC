class Solution {
public:
    
    void rec(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        
        if( i >= nums.size() ) {
            
            res.push_back(curr);
            return;
            
        }
        
        // include ith integer
        
        curr.push_back(nums[i]);
        
        rec(nums, res, curr, i+1);
        
        // dont include ith integer
        
        curr.pop_back();
        
        while(i+1 <nums.size() && nums[i] == nums[i+1]) 
            i++;
        
        rec(nums, res, curr, i+1);
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        vector<int> curr;
        
        sort(nums.begin(), nums.end());
        
        rec(nums, res, curr, 0);
        
        return res;
    }
};