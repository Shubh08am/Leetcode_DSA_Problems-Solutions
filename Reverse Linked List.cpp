class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        while(p != NULL){
            ListNode* next = p->next;
            p->next = q;
            q = p;
            p= next;
        }  
    return q;
     }};
