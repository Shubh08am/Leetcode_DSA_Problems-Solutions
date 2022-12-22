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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false; //no node
        
        targetSum-=root->val;
        
// check for leaf node
        if(targetSum==0 && root->left==nullptr && root->right==nullptr) return true;
        
        // recursive call to traverse left and right sub-tree
        bool leftSubTrree =  hasPathSum(root->left,targetSum) ;
        bool rightSubTree = hasPathSum(root->right,targetSum) ;
   
       bool result = leftSubTrree|rightSubTree;
        return result ;
    }
};
