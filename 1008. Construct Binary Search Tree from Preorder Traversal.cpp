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

   TreeNode*constructBST(int& pointAt , vector<int>& preorder , int upperBound){ 

//if upperBound is less than poinAt value or not possible to insert node -> return NULL;
//remember to check first poinAt pos otherwise runtime error comes.
       if( pointAt==preorder.size() || upperBound < preorder[pointAt]) {
           return NULL;
       }
       TreeNode* root = new TreeNode(preorder[pointAt]);
       pointAt++;
       //now,insert node in correct places 
       //when going left upperbound is root->val
       root->left = constructBST(pointAt,preorder,root->val);
       //when going right take upperbound value only
       root->right = constructBST(pointAt,preorder,upperBound);
            
       return root;
   }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //assign range method 
        int pointAt=0;  
        return  constructBST(pointAt,preorder,INT_MAX);
    }
};
