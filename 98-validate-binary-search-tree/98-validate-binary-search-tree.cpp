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
    
    void inOrder(TreeNode* root, vector<int> &arr) {
        
        if(root == NULL)
            return;
        
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<int> inOrderTrv;
        
        inOrder(root, inOrderTrv);
        
        for(int i=0; i<inOrderTrv.size()-1; i++) {
            
            if(!(inOrderTrv[i] < inOrderTrv[i+1]))
                return false;
        }
        
        return true;
    }
};