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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*dummy = head->next ; 
        head->next = swapPairs(head->next->next);//recursion used 
    //    cout<<head->val<<"\n";
        dummy->next=head;
    //    cout<<dummy->val<<" d\n";
        return dummy;
    }
};
