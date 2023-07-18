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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // BRUTE -> TAKE EACH NODE FROM A OR B AND COMPARE WITH EVERY NODE FROM B OR A -> O(LEN_A*LEN_B)
        // OPTIMIZED AT SC COST -> HASHING -> O(LEN_A+LEN_B)
    /*    unordered_map<ListNode*,bool>a; 
        int pos = 0 ; 
        while(headA){
            a[headA]=1;
            headA=headA->next;
        }
         while(headB){
             if(a.find(headB)!=a.end()) return headB;
             else a[headB]=1;
            headB=headB->next;
        }
    return NULL;
    */
    //OPTIMIZED APPROACH - 1 
    // t.c -> O(LEN_A+LEN_B)+O(abs(LEN_B-LEN_A))+O(min(LEN_B,LEN_A)) -> O(2*max(LEN_B,LEN_A)) at worst case
    //s.c - > O(1)
 /*   int lena = 0 , lenb=0 ; 
    ListNode*A=headA,*B=headB;
    while(A){
            lena++;
            A=A->next;
    }
    while(B){
            lenb++;
            B=B->next;
    }
    int maxi = max(lena,lenb) ; 
    int mini = min(lena,lenb) ; 
    int move = maxi-mini ; 
    if(maxi==lenb){
         while(move--) headB=headB->next;
    }
    else if(maxi==lena){
         while(move--) headA=headA->next;
    }
    while(headA&&headB){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return NULL;
*/
  //OPTIMIZED APPROACH - 2
    // t.c -> O(LEN_A+LEN_B)
    //s.c - > O(1)
    if(!headA || !headB) return NULL;
    ListNode*d1=headA,*d2=headB;
    while(d1!=d2){
        if(d1==NULL){
            d1=headB;
        }
        else d1=d1->next;
         if(d2==NULL){
            d2=headA;
        }
        else d2=d2->next;
    }   
    return d1; // no-intersection also handled as d1=d2=NULL THAN 
     }
};
