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

int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;

    int leftSideDepth = maxDepth(root->left);
    int rightSideDepth = maxDepth(root->right);

    int depth = max(leftSideDepth,rightSideDepth)+1;
    return depth;
    }

    bool isBalanced(TreeNode* root) {
           if(root==NULL) return 1;

           int leftSubTree = maxDepth(root->left);
           int rightSubTree = maxDepth(root->right);
           int diff = abs(rightSubTree-leftSubTree);

           return (diff<=1 and isBalanced(root->left) and isBalanced(root->right));
    }
};
