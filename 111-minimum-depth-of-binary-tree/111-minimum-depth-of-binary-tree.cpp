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
    int minDepth(TreeNode* root) {
        
        if(root == NULL) {
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int h1 = 9999;
        int h2 = 9999;
        
        if(root->left != NULL) {
            
            h1 = minDepth(root->left);
        }
        
        if(root->right != NULL) {
            
            h2= minDepth(root->right);
        }
        
        return (1+ min(h1, h2));
    }
};