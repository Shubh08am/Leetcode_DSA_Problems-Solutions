/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //brute force use visited concept 
    /*     unordered_set<ListNode*>cycle;
         ListNode*dummy=head;
         while(dummy){
             if(cycle.count(dummy)) return dummy;
             cycle.insert(dummy);
             dummy=dummy->next;
         }
         return NULL;
     */
    //optimized approach use floyd algorithm i.e slow and fast pointer 
     ListNode *slow = head , *fast = head , *start=head;
     if(head==NULL) return NULL;
     while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL){
         slow=slow->next; //move 1 step
         fast=fast->next->next;//move 2 step
         //meeting that is cycle present
         if(fast==slow) {
             //finding start of cycle now
             while(start->next!=NULL && slow->next!=NULL){
                if(slow==start) return slow;
                slow=slow->next;
                start=start->next;
             } 
              
        }
     }
     return NULL;//no cycle
    }
};
