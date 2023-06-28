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
TreeNode*build(vector<int>&inorder,int inStart , int inEnd ,vector<int>&postorder , int &postEnd ,  unordered_map<int,int>&postmap){
  

  //no more nodes left 
  if(inStart > inEnd) return NULL;

//position of post order node in inorder
int pos = postmap[postorder[postEnd]];
  
  //make root node of postEnd first 
  TreeNode*root = new TreeNode(postorder[postEnd]); 

//next time we will have a new postEnd for further nodes
postEnd-=1; 
  //go for right search 
   root->right = build(inorder,pos+1,inEnd,postorder,postEnd,postmap);

   //go for left search 
   root->left = build(inorder,inStart,pos-1,postorder,postEnd,postmap);


    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>postmap;

        for(int i=0;i<inorder.size() ; i++) {
            postmap[inorder[i]] = i;
        }
        int inStart = 0 , inEnd = inorder.size()-1;
        int postEnd = postorder.size()-1;
        TreeNode*root = build(inorder,inStart,inEnd,postorder,postEnd,postmap);
        
        return root;
    }
};
