/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        //left side
        if(p->val<root->val and q->val<root->val ){
            return lowestCommonAncestor(root->left,p,q);
        }
      //right side
        if(p->val>root->val and q->val>root->val){
          return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
