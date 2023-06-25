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
    void solve(TreeNode* root,long long currSum, long long targetSum,map<long long,long long>&mp,int&cnt){
        if(!root)return;
        
        currSum+=root->val;
        cnt+=mp[currSum-targetSum];
        mp[currSum]++;
        if(root->left)solve(root->left,currSum,targetSum,mp,cnt);
        if(root->right)solve(root->right,currSum,targetSum,mp,cnt);
        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        if(!root) return 0;
        map<long long,long long>mp;
        mp[0]=1;
        solve(root,0,targetSum,mp,cnt);
        return cnt;
    }
};
