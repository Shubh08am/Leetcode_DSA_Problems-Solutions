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
   
   TreeNode* LastRight(TreeNode* root){      
               //else move right
                while(root->right){
                   root=root->right;
              }
               return root;         
     }

     TreeNode* deleteandAttach(TreeNode* root){           
      //edge cases no left or right 
            if(!root->left) return root->right;
            else if(!root->right) return root->left;

            //when both available
            TreeNode*rightchild = root->right;
            //go left and find rightmost node and attach to it rightchild
            TreeNode*leftLastRightChild = LastRight(root->left);
            leftLastRightChild->right = rightchild;

            return root->left;
      }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
          
        //if the root is to be deleted 
        if(root->val == key) {
            return deleteandAttach(root);          
        }
       TreeNode*dummy = root;
        while(root){
            //finding the node to be deleted 
            if(root->val > key) {
                //node found to be deleted
                if(root->left!=NULL and root->left->val==key ) {
                    root->left =  deleteandAttach(root->left);
                    break;
                }

                //go left  
                else root=root->left;
            }

        else if(root->val < key) {
                //node found to be deleted
                if(root->right!=NULL and root->right->val==key ) {
                    root->right =  deleteandAttach(root->right);
                    break;
                }

                //go right  
                else root=root->right;
            }
        }
        return dummy;
    }
};
