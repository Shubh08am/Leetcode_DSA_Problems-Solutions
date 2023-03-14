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
//morris traversal
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorder;
         if(root==NULL) return preorder;
         
         while(root!=NULL){

            if(root->left==NULL){
                 preorder.push_back(root->val);
                 root=root->right;
            }

            else if(root->left!=NULL) {
             TreeNode*Rightmost = root->left;

             while(Rightmost->right!=NULL and Rightmost->right!=root){
                 Rightmost=Rightmost->right;
             }

             //when null :- create thread 
             if(Rightmost->right==NULL) {
                 Rightmost->right=root;
                 //take root in preorder
                 preorder.push_back(root->val);
                 root=root->left;
             }
               //thread already exist
             else if(Rightmost->right == root){
               //remove thread and move to right subtree 
               Rightmost->right= NULL;
               root=root->right;
             }

            }
        }
        return preorder;
    }
};
