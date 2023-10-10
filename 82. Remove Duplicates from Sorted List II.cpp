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
    void dup(ListNode*&head){
        while(head->next && head->val == head->next->val) {
                head=head->next;
            }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        /*
        1->1->2->2 
        ans->next = head  
        1=1 -> head=head->next on 2nd 1 
        1!=2 stop 
        ans->next = 2 
        now head on 2 
        2=2 -> move on last 2 and stop 
        update ans->next = null (head->next) 
        */
        ListNode*ans = new ListNode() ; 
        ListNode*res = ans ; 
        ans->next=head ;  
        while(head){
            if(head->next && head->val == head->next->val) {
            dup(head);
            ans->next=head->next; 
        // if(ans->next)   cout<<ans->next->val<<" ";
            }
            else{
                ans=ans->next;
            }
        //    cout<<"head " << head->val <<"\n";
        head=head->next;
        }
    return res->next;
    }
};
