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
TreeNode*first , *prev , *middle , *last; 

// traversal
   void inorder(TreeNode* root) {
    if(root==NULL) return;

         inorder(root->left) ; 
         
         //i.e  violation takes place as previous element is greater than next one
         if(prev and root->val < prev->val) {
            //first violation 
            if(!first) {
                first=prev;
                middle=root;
            }
            //second violation -> swap first with this 
            else if(first){
                last = root; 
            }
         }
         //update prev and check further 
         prev = root;
         inorder(root->right) ; 
    }

    void recoverTree(TreeNode* root) {
    /*Two case possible
    1. swap nodes are adjacent 
    2. swap nodes are not adjacent 
        
    1. when not adjacent 2 times the next element is smaller than previous element (inorder sorted of bst)
    2. when adjacent 1 time the next element is smaller than previous element (inorder sorted of bst)

    */ 
    first = NULL ; 
    middle = NULL ; 
    last = NULL; 

    //assign prev as min node and compare 
    prev = new TreeNode(INT_MIN) ; 
    inorder(root);
    
    //case 1 -> swap them
    if(first and last){
      swap(first->val,last->val);
    }
    //case 2 -> swap them
   else if(first and middle){
      swap(first->val,middle->val);
    }
    }
};
