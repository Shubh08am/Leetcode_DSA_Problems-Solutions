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
    ListNode* swapNodes(ListNode* head, int k) {
        //brute force :- use additional space 
        //optimized :- use two pointer approach 
        ListNode*slow = head , *fast = head , *atk = head ;
        k-=1;
        while(k--) atk=atk->next; 
        fast=atk->next; //moves n-k-1 times 
        //slow also moves //moves n-k-1 times and slow->next points at n-kth node on n-k-1th iteration
       while(fast!=NULL){ 
       //     cout<<fast->val <<" "<<slow->val<<"\n";
           fast=fast->next;
           slow=slow->next;
       }
    // cout<<atk->val <<" "<<slow->val;
        //swap values of kth node from front(atk) and end(slow) 
        swap(atk->val,slow->val);
        return head;
    }
};
