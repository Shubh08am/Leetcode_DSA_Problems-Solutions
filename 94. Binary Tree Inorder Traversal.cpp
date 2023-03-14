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
//mooris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(root==NULL) return inorder;

        TreeNode*curr = root ; //dummy node created 
        while(curr!=NULL){
            //case:-1 we move left and encounter NULL :- move right 
            if(curr->left==NULL) {
                //store curr node first in inorder
                inorder.push_back(curr->val) ; 
                curr=curr->right;
            }
            //case 2 :- left exist , so create & remove thread
          else if(curr->left!=NULL){
               TreeNode*prev = curr->left ; //move,prev to rightmost node of left subtree
               //thread doesn't exist than only move
               while(prev->right!=NULL and prev->right!=curr){
                prev=prev->right;
               }
                   //if null :- create thread 
                   if(prev->right==NULL){
                       prev->right=curr;
                       //move curr to left now
                       curr=curr->left;
                   }

                   //thread exist already remove it 
                   else if(prev->right==curr){
                       prev->right=NULL;
                       inorder.push_back(curr->val);
                       //move right left done
                       curr=curr->right;
                   }
          }
        }
        return inorder;
    }
};
