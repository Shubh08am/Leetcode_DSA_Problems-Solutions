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
    bool valid(TreeNode* root , long minValue , long maxValue){
        if(root==NULL) return 1;
        //out of range
        if(root->val >= maxValue || root->val<= minValue) return 0;
            //left and right
        return valid(root->left,minValue,root->val) && valid(root->right,root->val,maxValue);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
};
