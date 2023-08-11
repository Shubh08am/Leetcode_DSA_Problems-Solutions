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
    ListNode*findMiddle(ListNode*head){
        ListNode*slow = head , *fast = head->next ; // when even elements than for that case first element will be middle 
        while(fast && fast->next){
            slow=slow->next; 
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode * merge( ListNode*left ,  ListNode*right){
        
        if(!left) return right ; 
        if(!right) return left ;

        ListNode * merged = new ListNode(0) ; 
        ListNode * ans = merged ; 

        while(left && right){
            if(left->val < right->val){
                merged->next = left ; 
                merged = merged->next ;
                left=left->next;
            }
            else if(left->val>=right->val){
                merged->next = right ; 
                merged = merged->next ;
                right=right->next;
            }
        }

        while(left){
            merged->next = left ; 
            merged = merged->next  ;
            left=left->next;
        }

        while(right){
            merged->next = right ; 
            merged = merged->next ;
            right=right->next;
        }

    return ans->next ; 
    }
    ListNode* sortList(ListNode* head) {
        // merge sort on linked list 
        // links changed
        if(!head || !head->next) return head ; 

        //fast and slow -> mid find kro 
        ListNode*mid = findMiddle(head) ; 

        //break ll in 2 half 
        ListNode*left = head ; 
        ListNode*right = mid->next ; 
     //   cout<<mid->val<<" "<<right->val<<"\n";
        mid->next = NULL;
                
        //sort them 
        left = sortList(left) ; 
        right = sortList(right) ; 

        //merge both half 
        ListNode*sortedList = merge(left,right) ;
        
    return sortedList ; 
    }
};
