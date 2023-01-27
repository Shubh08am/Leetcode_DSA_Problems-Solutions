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
int maxPath(TreeNode* root, int &ans){
        if(root==NULL)
            return 0;
        
        int left = maxPath(root->left, ans);
        int right = maxPath(root->right, ans);
        
        int nodeMax = max(max(root->val, root->val + left + right), max(root->val + left, root->val + right));
        
        ans = max(ans, nodeMax);
        
        int SingleSum = max(root->val, max(root->val + left, root->val + right));
        
        return SingleSum;
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root, ans);
        
        return ans;
    }
};
