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
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root==subRoot;
        return root->val==subRoot->val && dfs(root->left,subRoot->left) && dfs(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        if(dfs(root,subRoot)) return 1;

        //what if not-starting from parent root node subtree 
        return isSubtree(root->left,subRoot) | isSubtree(root->right,subRoot);
    }
};
