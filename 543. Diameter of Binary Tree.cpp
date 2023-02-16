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
//max height of left sub-tree + right sub-tree
int maxHeight(TreeNode*root , int& diameter){
    if(root == NULL) {
        return 0;
    }
    int leftSubTreeHeight = maxHeight(root->left,diameter);
    int rightSubTreeHeight = maxHeight(root->right,diameter);
//keep doing in whole tree
    diameter = max(leftSubTreeHeight + rightSubTreeHeight, diameter);

    return 1+max(leftSubTreeHeight,rightSubTreeHeight);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        if(root==NULL) return 0;
        maxHeight(root,diameter);
        return diameter;
    }
};
