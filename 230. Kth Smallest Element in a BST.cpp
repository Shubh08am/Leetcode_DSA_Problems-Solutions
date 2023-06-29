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
public://morris traversal
//inorder property :- always sorted
    int kthSmallest(TreeNode* root, int k) {
        int reach=0,ans=0;
        while(root!=NULL){
            if(root->left==NULL){
                reach++;
                if(reach==k) {
                    ans = root->val;
                }
                root=root->right;
            }

            else if(root->left!=NULL){
                TreeNode*dummy = root->left;
                while(dummy->right!=NULL and dummy->right!=root){
                    dummy = dummy->right;
                }

                if(dummy->right==NULL){
                    dummy->right=root;
                    root=root->left;
                }

                else if(dummy->right ==root){
                  reach++;
                  dummy->right=NULL;
                  if(reach==k){
                      ans = root->val;
                  }
                  root=root->right;
                }
            }
        }
        return ans;
    }
};
