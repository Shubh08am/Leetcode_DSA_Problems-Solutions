/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 int maxx = 0;
public:
    int maxAncestorDiff(TreeNode* root, int mx = INT_MIN, int mn = INT_MAX) {
        if(nullptr == root)
            return 0;

        mx = max(mx, root -> val);
        mn = min(mn, root -> val);
        maxx = max(maxx, abs(mx - mn));
        maxAncestorDiff(root -> left, mx, mn); 
        maxAncestorDiff(root -> right, mx, mn); 
        
        return maxx;  
    }    

};
