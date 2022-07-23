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
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL) {
            
            return true;
        }
        
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        
        while(!st.empty()) {
            
            TreeNode* n1 = st.top();
            st.pop();
            TreeNode* n2 = st.top();
            st.pop();
            
            if(n1==NULL && n2==NULL)
                continue;
            
            else if(n1==NULL || n2==NULL || n1->val != n2->val)
                return false;
            
            else {
                
                st.push(n1->left);
                st.push(n2->right);
                st.push(n1->right);
                st.push(n2->left);
            }
        }
        
        return true;
    }
};