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
    int solve(TreeNode*root,TreeNode*parent,int&moves){
        if(!root) return 0;
        solve(root->left,root,moves);
        solve(root->right,root,moves);
        
        if(root->val > 1){
            //1 coin rkho bas root pe baaki extraCoin parent ko dedo  
            int extraCoin = root->val-1 ; 
            parent->val+=extraCoin  ; 
            moves+=extraCoin;//itne coins tho tree mein transfer honge hii as n nodes and n coins
        }
        if(root->val<1){
            //[4,0,null,null,0,null,0] 
            //kisi node pe <0 coin bhi honge jab requirement parent se fulfill krre hain tho 
            //tho jab uss node ki requirement parent se fulfill krre hain tho -ve ko +ve krdo  
            int deficitCoin = abs(root->val)+1 ; 
            parent->val-=deficitCoin  ; 
            moves+=deficitCoin;
        }
       // cout<<root->val<<" ";
        return moves;
    }
    int distributeCoins(TreeNode* root) {
        // root ke paas > 1 coins hain parent ko dedo extra and moves increase krdo   
       // root ke paas < 1 coins hain parent se lelo required coins and moves increase krdo 
        int moves=0;
        solve(root,root,moves);
        return moves;
    }
};
