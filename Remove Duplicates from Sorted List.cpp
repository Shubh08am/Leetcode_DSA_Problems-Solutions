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

    ListNode* deleteDuplicates(ListNode* head) {

   

        /*

        if(head==NULL) {

          return NULL;

      }  

       if(head->next ==NULL){

            return head;

        }

        

        ListNode*temp = head ; 

        

        while(temp and temp->next){

            

            if(temp->val == temp->next->val){

                temp->next=temp->next->next ;

            }

            else temp=temp->next;

        }

        return head ;

        

        */

               ListNode*temp = head ; 

 

        if(temp==NULL){

return NULL;

}

if(temp->next==NULL) {

return head;

}

while(temp!=nullptr and temp->next!=nullptr){

if(temp->val == temp->next->val)

{

    ListNode*del = temp->next;

    temp->next = temp->next->next;  

delete del;

}

else temp= temp->next;

}

        

return head;

    }

};
