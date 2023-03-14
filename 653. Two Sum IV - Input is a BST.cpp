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
     unordered_map<int,int>freq;
    bool findTarget(TreeNode* root, int k) {
        //brute force uses s.c -> o(n) 
        if(root==NULL) return false;
       if(freq.find(k-root->val) != freq.end()) return true;
        freq[root->val]++;
       if (findTarget(root->left,k)) return true;
       else if( findTarget(root->right,k)) return true;

       return false;
    }
};
