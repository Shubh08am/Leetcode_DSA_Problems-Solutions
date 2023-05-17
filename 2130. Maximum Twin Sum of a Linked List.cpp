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
     //APPROACH-1 USING ADDITIONAL SPACE
    int pairSum2(ListNode* head) {
      vector<int>nodes;
      ListNode*dummy=head ; 
      int maxPairSum=0;
      while(dummy) {
          nodes.push_back(dummy->val);
          dummy=dummy->next;
      }
      //Two Pointers now 
      int i=0,j=nodes.size()-1;
      while(i<j){
        maxPairSum=max(maxPairSum,nodes[i++]+nodes[j--]);
      }
      return maxPairSum;
    }
    int pairSum(ListNode* head) {
         
        // return pairSum2(head) ;   //APPROACH-1 USING ADDITIONAL SPACE

         //APPROACH-2 USING TWO POINTERS [REVERSE SECOND HALF] 
        int maxPairSum=0;
        ListNode*slow=head,*fast=head; 
        //FIND MIDDLE USING SLOW AND FAST POINTER 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; //moved once 
        //    cout<< slow->val << " " << fast->val <<"\n";
            fast=fast->next->next; //moved twice 
             
        }
       

        //SLOW POINTS AT MIDDLE 
        ListNode*prev=NULL; 
         //NOW,REVERSE LL FROM SLOW TO LAST NODE 

        while(slow){
            //preserve slow->next 
            ListNode*preserve = slow->next ; 
            //point slow->next to prev 
            slow->next=prev;
            //update prev to slow 
            prev=slow; 
            //move,slow ahead to preserve 
            slow=preserve ; 
        }

        // [1,2,3,4,5,6] -> [1,2,3,6,5,4] ->    Now,use two pointer one from start and one from middle next 
        
         ListNode*start=head ; 
        //prev POINTS AT MIDDLE 
        while(prev){
            int curr = start->val + prev->val; 
            maxPairSum=max(maxPairSum,curr);
            prev=prev->next;
            start=start->next;
        }
        return maxPairSum;
    }
};
