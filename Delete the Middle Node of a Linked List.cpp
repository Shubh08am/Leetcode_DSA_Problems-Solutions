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

    ListNode* deleteMiddle(ListNode* head) {

    

            ListNode*temp = head ; 

            ListNode*p = NULL ; 

        int len = 0 , cnt = 0 , c = 0; 

            while(temp){

                temp=temp->next ; 

                len++;

            } 

       if(len&1){ 

          

            cnt = len/2;

            

            temp = head ;  

           if(temp->next == nullptr) {

             return nullptr ;   

           }

            while(temp and c<cnt-1)

            {

        temp = temp->next ;

    

                c++;

            } 

if(temp->next!= NULL) { temp->next = temp->next->next; } 

           

            return head ; 

        }

        

       else{

            c = 0  ; temp = head ;

        cnt = len/2 + 1 ;

           while(temp and c<cnt-2){

               temp = temp->next ; 

               c++;

           }

           if(temp->next!= NULL) {

               temp->next = temp->next->next; }/*

           if(temp->next->next = nullptr) {

delete(temp->next); }*/

   // temp->next = temp->next->next ;

            return head ;

        }

      return NULL ;  

    }

};
