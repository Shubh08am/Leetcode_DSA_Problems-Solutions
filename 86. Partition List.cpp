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
    ListNode* partition(ListNode* head, int x) {
        // 2 LL -> one < x and one >=x 
        // merge both LL 
        ListNode*smaller = new ListNode(-1) ; 
        ListNode*larger = new ListNode(-1)  ; 
        ListNode*startOfSmaller = smaller ;
        ListNode*startOfLarger = larger ;

        while(head){
            if(head->val < x) {
                smaller->next = head ; 
                smaller = smaller->next  ;
            }
            if(head->val >= x) {
                larger->next = head ; 
                larger = larger->next  ;
            }
            head = head->next;
        }
        larger->next = NULL;
        smaller->next = startOfLarger->next ;
        return startOfSmaller->next; 
    }
};
