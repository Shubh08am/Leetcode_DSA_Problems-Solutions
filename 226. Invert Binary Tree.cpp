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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL ;
        //take right-subtree of root in rht 
        TreeNode*rht = invertTree(root->right);
        //take left-subtree of root in lft 
        TreeNode*lft = invertTree(root->left);
        //give-root->left rht link
        root->left = rht ; 
       //give-root->right lft link
        root->right = lft ; 
        return root;
    }
};
