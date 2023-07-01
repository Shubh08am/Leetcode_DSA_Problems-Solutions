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
    void flatten(TreeNode* root) {
      //morris traversal approach  :- S.C = O(1)
      if(!root) return;
      
      while(root){
     if(root->left){
      TreeNode*prev = root->left;
      //move it to rightmost 
      while(prev->right) prev=prev->right ;
 
    //change the link 
    
    prev->right = root->right;         
    root->right=root->left;
    root->left = NULL;
    }
     //move root 
    root=root->right;
    }
    
 }
}; 
