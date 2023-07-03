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
    vector<TreeNode*>solve(int s,int e,map<pair<int,int>,vector<TreeNode*>>&dp){
        vector<TreeNode*>bst; 
        if(s>e){
            bst.push_back(NULL);
            return bst;
        } 
        if(s==e){
            bst.push_back(new TreeNode(s));
            return bst;
        }
        if(dp.find({s,e})!=dp.end()) return dp[{s,e}];
         for(int j=s;j<=e;j++){ 
            auto left = solve(s,j-1,dp) ; 
            auto right= solve(j+1,e,dp) ;
            
            //Now,exploring all ways 
            for(auto&l:left){
                for(auto&r:right){
                    // (root,root->left,root->right)
                    TreeNode*root= new TreeNode(j,l,r) ;  
                    bst.push_back(root);
                }
            }
        }
    return dp[{s,e}]=bst;
    }
    vector<TreeNode*> generateTrees(int n) {
    /*       i 
        i-1      n-i 
    */
    map<pair<int,int>,vector<TreeNode*>>dp;
    return solve(1,n,dp);
    }
};
