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
void inorder(TreeNode*root,vector<int>&in){
    if(!root) return  ;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>m;
        vector<pair<int,int>>vp;
        vector<int>in;int mini=INT_MAX,maxi=0;
        inorder(root,in);
        for(auto it:in) m[it]++;

        for(auto it:m)  { 
              mini=min(mini,it.second);
              maxi=max(maxi,it.second);
              vp.push_back({it.second,it.first});
              }
        
        sort(vp.rbegin(),vp.rend()) ; 
        in.clear();
        for(auto it:vp)  {
          if(it.first==maxi)    in.push_back(it.second); 
        }
       // cout<<mini<<" "<<maxi;
     //  if(mini!=maxi) in.pop_back();
        return in;
    }
};
