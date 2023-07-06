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
    int solve(TreeNode*root,int v,int&good){
        if(!root) return 0;

        int ans=0;
        if(root->left){
             if(v<=root->left->val){
                ans = 1 + solve(root->left,root->left->val,++good);
            }
            else ans = solve(root->left,v,good);
        }
        if(root->right){
            if(v<=root->right->val){
                ans = 1 + solve(root->right,root->right->val,++good);
            }
            else ans = solve(root->right,v,good);
        }
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int good = 1 ; 
        solve(root,root->val,good);
        return good;
    }
};
