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
//without extra space (only recursive space used)
 void inorder(TreeNode* root, TreeNode* &previousNode, int& diff){
        if(root==NULL){
            return;
        }
        inorder(root->left, previousNode, diff);
        if(previousNode!=NULL) {
            int prevdiff = abs(root->val - previousNode->val) ;
            diff = min(diff, prevdiff);
            }
            //update previous node with current root value
          previousNode = root;
          inorder(root->right, previousNode, diff);
    }       
    int getMinimumDifference(TreeNode* root) {
     TreeNode* previousNode = NULL;
        int diff = 100001;
        inorder(root, previousNode, diff);
        return diff;
    }
};
