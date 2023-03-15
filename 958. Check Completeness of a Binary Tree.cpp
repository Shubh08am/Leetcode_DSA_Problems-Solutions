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
    int NumberofNodes(TreeNode*root){
        if(!root) return 0;
         return 1+NumberofNodes(root->left)+NumberofNodes(root->right);
    }
    bool completeBST(TreeNode*root,int totalNodes,int currentPos){
        if(!root) return 1;
        int currentNodeIndex=currentPos;
        int leftNodeIndex = 2*currentNodeIndex+1;
        int rightNodeIndex = 2*currentNodeIndex+2;
        //if currentNodeIndex crosses totalNodes than not a bst
      //  cout<<currentNodeIndex<<" cn "; 
        if(currentNodeIndex>=totalNodes) return 0;
        //else call recursively 
       return completeBST(root->left,totalNodes,leftNodeIndex) and completeBST(root->right,totalNodes,rightNodeIndex);
    }
    bool isCompleteTree(TreeNode* root) {
         int totalNodes=NumberofNodes(root);
       cout<<totalNodes<<" ";
         int currentPos = 0;
        return completeBST(root,totalNodes,currentPos);
     }
};
