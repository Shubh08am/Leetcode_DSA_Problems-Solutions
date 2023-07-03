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
    void dfs(TreeNode*a , TreeNode*b , int level){
        if(a==NULL and b==NULL) return;
        //swap at odd level  
        if(level&1) swap(a->val,b->val);
       // swap the value of left's left children with value of right's right children 
        dfs(a->left,b->right,level+1);
    // swap the value of left's right children with value of right's left children
        dfs(a->right,b->left,level+1);

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        //bfs is very intutive 
        //therefore do dfs :) 
        int level=1;
        dfs(root->left,root->right,level);
        return root;
    }
}; 
