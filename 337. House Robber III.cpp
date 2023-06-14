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
    int solve(TreeNode* root , map<TreeNode*,int>&dp){
        if(root==NULL){
            return 0;
        }

        if(dp.find(root)!=dp.end()) return dp[root];

        //AT EVERY NODE TWO CASE POSSIBLE :-

        //CASE 1 :- ROBBERY
        //CASE 2 :- NO ROBBERY 
        
        //CASE 1 :- ROBBERY
        int robbery = root->val ; //current house robbed

        //Now,we need to skip next consecutive house i.e root->left and root->right
        //and we can now rob houses  root->left->left and root->left->right
       //  root->right->right and root->right->left respectively

        if(root->left!=NULL){
            robbery+=solve(root->left->left,dp)+solve(root->left->right,dp);
        }
        if(root->right!=NULL){
            robbery+=solve(root->right->right,dp)+solve(root->right->left,dp);
        }

        //CASE 2:- NO ROBBERY
        int noRobbery = solve(root->left,dp)+solve(root->right,dp);
        
    return dp[root]=max(robbery,noRobbery);
    }
    int rob(TreeNode* root) {
        //dp on trees
        //can't rob two consecutive nodes
        map<TreeNode*,int>dp ; 
        return solve(root,dp);

    }
};
