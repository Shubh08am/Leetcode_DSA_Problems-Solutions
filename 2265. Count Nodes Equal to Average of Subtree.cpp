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
    pair<int,int> dfs(TreeNode*root,int &avg){
        if(!root) return {0,0} ;
        
        auto left = dfs(root->left,avg);
        auto right = dfs(root->right,avg);

        int sum = root->val+left.first+right.first;
        int noOfNode = 1+left.second+right.second;

        if(root->val==sum/noOfNode) avg++;

    return {sum,noOfNode};
    }
    int averageOfSubtree(TreeNode* root) {
        int avg=0;
        dfs(root,avg);
        return avg;
    }
};
