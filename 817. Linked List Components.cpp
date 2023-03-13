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
class Solution {
public: 
     
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>appeared ; 
        int components=0;
        for(auto&val : nums){
            appeared[val]++;
        } 
        int prevNodeVal=-1;
        ListNode*dummy = head ; 
        while(dummy!=NULL){
            int nodeVal = dummy->val ; 
            if(appeared[nodeVal]==0 && appeared[prevNodeVal]>0){
                components++;
            } 
            prevNodeVal=nodeVal;
            dummy=dummy->next;
            if(dummy==NULL && appeared[prevNodeVal]>0){
            components++;
            }
        }

        return components;
    }
};
