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
//Same Concept of LargestBST
 class NodeInfo{
     public:
     int maxNode , minNode , maxSize , maxSum;
     //initialized
     NodeInfo(int minNode , int maxNode , int maxSize , int maxSum) {
         this->minNode = minNode;
         this->maxNode = maxNode;
         this->maxSize = maxSize;
         this->maxSum = maxSum;
     }
 };

class Solution {
   public :
   NodeInfo largestSumBST(TreeNode*root , int&ans){
       if(!root) {
           return NodeInfo(INT_MAX,INT_MIN,0,0) ;
       }
       //post order
       NodeInfo leftSum = largestSumBST(root->left , ans);
       NodeInfo rightSum = largestSumBST(root->right , ans);

       //check for bst 
      if(leftSum.maxNode < root->val && root->val<rightSum.minNode){
          //valid bst take it and try to maximize the sum
         ans = max(ans,leftSum.maxSum + rightSum.maxSum + root->val);
return NodeInfo(min(root->val,leftSum.minNode)  , max(root->val,rightSum.maxNode) ,leftSum.maxSize + rightSum.maxSize +1 , leftSum.maxSum + rightSum.maxSum + root->val);
      }
     //not a valid bst
      return NodeInfo( INT_MIN ,INT_MAX  ,max(leftSum.maxSize , rightSum.maxSize) , 0);
   }
     int maxSumBST(TreeNode* root) {
        int ans=0;
          largestSumBST(root,ans);
        //  cout<<ans<<"\n";
          return ans;
    }
};
