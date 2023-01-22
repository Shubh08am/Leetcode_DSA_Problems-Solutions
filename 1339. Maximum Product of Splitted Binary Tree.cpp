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
    const int mod=1e9+7;
        
                int sumtree(TreeNode* root)  {
                        if(root==NULL) return 0;
                                return root->val+sumtree(root->left)+sumtree(root->right);
                                    }
                                        
                                            long sum=0,res=0;
                                                int solve(TreeNode* root)
                                                    {
                                                            if(root==NULL) return 0;
                                                                    int lsum=solve(root->left);
                                                                            int rsum=solve(root->right);
                                                                                    
                                                                                            if(lsum>res/(sum-lsum)) res=(sum-lsum)*lsum;
                                                                                                    if(rsum>res/(sum-rsum)) res=(sum-rsum)*rsum;
                                                                                                            return root->val+lsum+rsum;
                                                                                                                    
                                                                                                                        }
    int maxProduct(TreeNode* root) {
          sum=sumtree(root);
                  solve(root);
                          return res%mod;
    }
};
