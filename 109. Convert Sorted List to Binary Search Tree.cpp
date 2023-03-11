/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* binarySearch(vector<int>& nums , int start , int end){ 
       if(start<=end){
           int mid = start + (end-start)/2;
           TreeNode*root=new TreeNode(nums[mid]) ; 
           //left insertion 
           root->left=binarySearch(nums,start,mid-1);
           root->right = binarySearch(nums,mid+1,end);
           return root;
       }
       return NULL;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        ListNode* dummy = head;
        while(dummy){
            nums.push_back(dummy->val);
            dummy=dummy->next;
        }
        //Now,find mid all value in left are smaller and in right are greater than mid apply binary search 
        //But,still T.C will be O(n) as going on every node
        return binarySearch(nums,0,nums.size()-1);
    }
};
