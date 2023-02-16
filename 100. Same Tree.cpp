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
    bool isSameTree(TreeNode* p, TreeNode* q) {

       //both null
          if(p==NULL and q==NULL){
            return 1;
        }

        //one null i.e not identical
        if(p==NULL || q==NULL){
            return 0;
        }
  
        //compare values
        if(p->val!=q->val) {
             return 0;
         }

        //recursive call 
      return isSameTree(p->right, q->right) && isSameTree(p->left, q->left) ; 
         
    }
};
