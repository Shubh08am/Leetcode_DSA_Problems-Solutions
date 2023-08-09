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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head ;

        ListNode*dummy=new ListNode(0);
        dummy->next = head ;
        ListNode*prev = dummy ; 
        int cnt = 1 ; 
        while(cnt<left){
            cnt++;
            prev = head ;
            head=head->next; 
        }
         cout<<prev->val<<" "<<head->val<<"\n";

        ListNode * curr = head ; 
        int start = left ; 
        while(start<right){
            ListNode * forward=curr->next; 
            curr->next = forward->next ; 
            forward->next = prev->next;
            prev->next=forward ;
            start++;
        }
    return dummy->next;
    }
};
