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
// T.C - O(((log(n))^2)
  
    int countNodes(TreeNode* root) {
       if(root==NULL) return 0;

       int leftheightvalue = 0 ;
       int rightheightvalue = 0;
      TreeNode*lefttraverse = root , *righttraverse=root;

       while(lefttraverse!=NULL){
          leftheightvalue++;
          lefttraverse=lefttraverse->left;
      }   
       while(righttraverse!=NULL){
          rightheightvalue++;
          righttraverse=righttraverse->right;
      }  
      //full binary tree
       if(leftheightvalue == rightheightvalue ) return (1<<leftheightvalue) - 1 ;

       //else count the current node and call for left and right
       return 1+countNodes(root->left) + countNodes(root->right) ; 
    }
};
