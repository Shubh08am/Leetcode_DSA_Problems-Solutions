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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
        BRUTE -> O(N*K) TAKE LAST NODE AND INSERT IN FRONT FOR K TIMES -> N FOR FINDING LAST NODE
        */
        if(!head || !head->next || k==0) return head;
        int len = 0 ; 
        ListNode*t=head,*p=head,*bt=head;
        while(t) {
            len++;
            bt=t;
            t=t->next;
        }
        bt->next=head; // circular ll formed 
        //CASE 1 - K<LEN  //CASE 2 - K>= LEN 
        k%=len;
        k =len-k ;
        //set len-kth node to null 
        while(k-->1){
            p=p->next;
        }
        head=p->next;
        p->next=NULL;
    return head;
    }
};
