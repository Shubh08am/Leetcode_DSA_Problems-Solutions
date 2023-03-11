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
     TreeNode* binarysearch(vector<int>& nums , int start , int end){ 
          
          if(start<=end){
            int mid = start + (end-start)/2;
            TreeNode*root= new TreeNode(nums[mid]);
            root->left = binarysearch(nums,start,mid-1);
            root->right = binarysearch(nums,mid+1,end);
            return root ;
          }
    return NULL; ;
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //find mid all value in left are smaller and in right are greater than mid
        return binarysearch(nums,0,nums.size()-1);
    }
};
