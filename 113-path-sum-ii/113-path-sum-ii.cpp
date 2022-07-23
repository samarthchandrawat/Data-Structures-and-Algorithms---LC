/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode* root, vector<vector<int>> &res, vector<int> curr, int curr_sum, int target_sum) {
        
        if(root == NULL) {
            return;
        }
        
        curr.push_back(root->val);
        curr_sum += root->val;
        
        if(root->left == NULL && root->right == NULL && curr_sum == target_sum) {
            
            res.push_back(curr);
            return;
        }
        
        rec(root->left, res, curr, curr_sum, target_sum);
        rec(root->right, res, curr, curr_sum, target_sum);
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> curr;
    
        rec(root, res, curr, 0, targetSum);
        return res;
    }
};