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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1) return {new TreeNode(0)} ;
        if(n%2==0)  return {} ; 
        vector<TreeNode*> ans; 
        for(int i=1;i<n;i+=2){
         //form left and right sub-tree 
        auto leftSubTree = allPossibleFBT(i);
        auto rightSubTree = allPossibleFBT(n-i-1);

          for(auto&l:leftSubTree){
              for(auto&r:rightSubTree){
              TreeNode*node=new TreeNode(0);
              node->left=l;
              node->right=r;
              ans.push_back(node);
            }
          }
     }
    return ans;   
    }
};
