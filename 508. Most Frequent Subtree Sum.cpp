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
    map<int,int>freq;
    int dfs(TreeNode*root){
        if(!root) return 0;
        int leftSum = dfs(root->left) ;
        int rightSum = dfs(root->right) ;
        freq[root->val+leftSum+rightSum]++;
        return root->val+leftSum+rightSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxFreq=0;
        vector<int>ans;
        dfs(root);
        for(auto&it:freq){
            maxFreq=max(maxFreq,it.second);
        }
        for(auto&it:freq){
            if(it.second==maxFreq) ans.push_back(it.first);
        }
    return ans;
    }
};
