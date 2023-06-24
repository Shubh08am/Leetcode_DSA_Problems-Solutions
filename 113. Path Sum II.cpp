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
    bool isLeaf(TreeNode*root){
        return !root->left && !root->right ;
    }
    void solve(TreeNode*root,int targetSum,vector<vector<int>>&path,vector<int>&currPath){
        if(!root) return;
     //   cout<<targetSum<<" ";
        targetSum-=root->val;
        currPath.push_back(root->val);
        if(targetSum==0 && isLeaf(root)){
            path.push_back(currPath);
        }
        if(root->left) solve(root->left,targetSum,path,currPath);
        if(root->right) solve(root->right,targetSum,path,currPath);
        currPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>path;
        vector<int>currPath;
        solve(root,targetSum,path,currPath);
        return path;
    }
};
