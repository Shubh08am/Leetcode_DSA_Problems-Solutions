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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        TreeNode*dummy = root;
        bool flg = true;
       while(flg){

        if(dummy->val<=val){
          if(dummy->right!=NULL) dummy=dummy->right;
          else if(dummy->right==NULL) {
              dummy->right=new TreeNode(val);//insert new node at leaf 
               flg=false;
          }
        }
        else if(dummy->val>val){
         if(dummy->left!=NULL) dummy=dummy->left;
          else if(dummy->left==NULL) {
              dummy->left=new TreeNode(val);//insert new node at leaf 
              flg=false;
        }
        }

       }
    return root;
    }
};
